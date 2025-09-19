package com.example.quickaid.pages;

import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;
import android.widget.Toast;
import androidx.annotation.NonNull;
import androidx.appcompat.app.AppCompatActivity;
import androidx.recyclerview.widget.LinearLayoutManager;
import androidx.recyclerview.widget.RecyclerView;
import com.example.quickaid.R;
import com.example.quickaid.login.SessionManager;
import com.example.quickaid.login.User;
import com.google.firebase.database.DataSnapshot;
import com.google.firebase.database.DatabaseError;
import com.google.firebase.database.DatabaseReference;
import com.google.firebase.database.FirebaseDatabase;
import com.google.firebase.database.ValueEventListener;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;

public class Friend extends AppCompatActivity {

    private EditText phoneSearchEt;
    private Button searchBtn, sendRequestBtn;
    private RecyclerView requestsRecyclerView, friendsRecyclerView;
    private TextView foundUserTv;

    private DatabaseReference usersRef;
    private String currentUserPhone;
    private User foundUser;

    private List<User> friendRequestsList;
    private List<User> friendsList;
    private FriendRequestsAdapter requestsAdapter;
    private FriendsAdapter friendsAdapter;

    private SessionManager sessionManager;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_friend);

        sessionManager = new SessionManager(this);

        // Get current user phone from SessionManager
        currentUserPhone = sessionManager.getPhone();

        if (currentUserPhone == null || currentUserPhone.isEmpty()) {
            Toast.makeText(this, "User not logged in", Toast.LENGTH_SHORT).show();
            finish();
            return;
        }

        initializeViews();
        setupRecyclerViews();
        loadFriendRequests();
        loadFriends();
    }

    private void initializeViews() {
        phoneSearchEt = findViewById(R.id.phoneSearchEt);
        searchBtn = findViewById(R.id.searchBtn);
        sendRequestBtn = findViewById(R.id.sendRequestBtn);
        foundUserTv = findViewById(R.id.foundUserTv);
        requestsRecyclerView = findViewById(R.id.requestsRecyclerView);
        friendsRecyclerView = findViewById(R.id.friendsRecyclerView);

        usersRef = FirebaseDatabase.getInstance().getReference("Users");

        searchBtn.setOnClickListener(v -> searchUserByPhone());
        sendRequestBtn.setOnClickListener(v -> sendFriendRequest());
    }

    private void setupRecyclerViews() {
        friendRequestsList = new ArrayList<>();
        friendsList = new ArrayList<>();

        requestsAdapter = new FriendRequestsAdapter(friendRequestsList);
        friendsAdapter = new FriendsAdapter(friendsList);

        requestsRecyclerView.setLayoutManager(new LinearLayoutManager(this));
        requestsRecyclerView.setAdapter(requestsAdapter);

        friendsRecyclerView.setLayoutManager(new LinearLayoutManager(this));
        friendsRecyclerView.setAdapter(friendsAdapter);
    }

    private void searchUserByPhone() {
        String phone = phoneSearchEt.getText().toString().trim();

        if (phone.isEmpty()) {
            Toast.makeText(this, "Please enter a phone number", Toast.LENGTH_SHORT).show();
            return;
        }

        if (phone.equals(currentUserPhone)) {
            Toast.makeText(this, "Cannot add yourself as friend", Toast.LENGTH_SHORT).show();
            return;
        }

        usersRef.child(phone).addListenerForSingleValueEvent(new ValueEventListener() {
            @Override
            public void onDataChange(@NonNull DataSnapshot snapshot) {
                if (snapshot.exists()) {
                    foundUser = snapshot.getValue(User.class);
                    if (foundUser != null) {
                        foundUserTv.setText("Found: " + foundUser.getUsername());
                        sendRequestBtn.setVisibility(View.VISIBLE);
                    }
                } else {
                    foundUserTv.setText("User not found");
                    sendRequestBtn.setVisibility(View.GONE);
                    Toast.makeText(Friend.this, "User not found", Toast.LENGTH_SHORT).show();
                }
            }

            @Override
            public void onCancelled(@NonNull DatabaseError error) {
                Toast.makeText(Friend.this, "Error: " + error.getMessage(), Toast.LENGTH_SHORT).show();
            }
        });
    }

    private void sendFriendRequest() {
        if (foundUser == null) return;

        // Check if already friends or request already sent
        usersRef.child(currentUserPhone).addListenerForSingleValueEvent(new ValueEventListener() {
            @Override
            public void onDataChange(@NonNull DataSnapshot snapshot) {
                User currentUser = snapshot.getValue(User.class);
                if (currentUser != null) {
                    // Check if already friends
                    if (currentUser.getFriends() != null && currentUser.getFriends().containsKey(foundUser.getPhone())) {
                        Toast.makeText(Friend.this, "Already friends", Toast.LENGTH_SHORT).show();
                        return;
                    }

                    // Check if request already sent
                    if (currentUser.getSentRequests() != null && currentUser.getSentRequests().containsKey(foundUser.getPhone())) {
                        Toast.makeText(Friend.this, "Request already sent", Toast.LENGTH_SHORT).show();
                        return;
                    }

                    // Send request
                    HashMap<String, Object> updates = new HashMap<>();

                    // Add to current user's sent requests
                    updates.put("sentRequests/" + foundUser.getPhone(), true);

                    // Add to found user's friend requests
                    updates.put(foundUser.getPhone() + "/friendRequests/" + currentUserPhone, true);

                    usersRef.updateChildren(updates)
                            .addOnSuccessListener(aVoid -> {
                                Toast.makeText(Friend.this, "Friend request sent", Toast.LENGTH_SHORT).show();
                                sendRequestBtn.setVisibility(View.GONE);
                            })
                            .addOnFailureListener(e -> {
                                Toast.makeText(Friend.this, "Failed to send request", Toast.LENGTH_SHORT).show();
                            });
                }
            }

            @Override
            public void onCancelled(@NonNull DatabaseError error) {
                Toast.makeText(Friend.this, "Error: " + error.getMessage(), Toast.LENGTH_SHORT).show();
            }
        });
    }

    private void loadFriendRequests() {
        usersRef.child(currentUserPhone).child("friendRequests")
                .addValueEventListener(new ValueEventListener() {
                    @Override
                    public void onDataChange(@NonNull DataSnapshot snapshot) {
                        friendRequestsList.clear();
                        for (DataSnapshot requestSnapshot : snapshot.getChildren()) {
                            String requesterPhone = requestSnapshot.getKey();
                            if (requesterPhone != null) {
                                usersRef.child(requesterPhone).addListenerForSingleValueEvent(new ValueEventListener() {
                                    @Override
                                    public void onDataChange(@NonNull DataSnapshot userSnapshot) {
                                        User requester = userSnapshot.getValue(User.class);
                                        if (requester != null) {
                                            friendRequestsList.add(requester);
                                            requestsAdapter.notifyDataSetChanged();
                                        }
                                    }

                                    @Override
                                    public void onCancelled(@NonNull DatabaseError error) {
                                        Toast.makeText(Friend.this, "Error loading requester", Toast.LENGTH_SHORT).show();
                                    }
                                });
                            }
                        }
                    }

                    @Override
                    public void onCancelled(@NonNull DatabaseError error) {
                        Toast.makeText(Friend.this, "Error loading requests", Toast.LENGTH_SHORT).show();
                    }
                });
    }

    private void loadFriends() {
        usersRef.child(currentUserPhone).child("friends")
                .addValueEventListener(new ValueEventListener() {
                    @Override
                    public void onDataChange(@NonNull DataSnapshot snapshot) {
                        friendsList.clear();
                        for (DataSnapshot friendSnapshot : snapshot.getChildren()) {
                            String friendPhone = friendSnapshot.getKey();
                            if (friendPhone != null) {
                                usersRef.child(friendPhone).addListenerForSingleValueEvent(new ValueEventListener() {
                                    @Override
                                    public void onDataChange(@NonNull DataSnapshot userSnapshot) {
                                        User friend = userSnapshot.getValue(User.class);
                                        if (friend != null) {
                                            friendsList.add(friend);
                                            friendsAdapter.notifyDataSetChanged();
                                        }
                                    }

                                    @Override
                                    public void onCancelled(@NonNull DatabaseError error) {
                                        Toast.makeText(Friend.this, "Error loading friend", Toast.LENGTH_SHORT).show();
                                    }
                                });
                            }
                        }
                    }

                    @Override
                    public void onCancelled(@NonNull DatabaseError error) {
                        Toast.makeText(Friend.this, "Error loading friends", Toast.LENGTH_SHORT).show();
                    }
                });
    }

    private void acceptFriendRequest(User requester) {
        HashMap<String, Object> updates = new HashMap<>();

        // Remove from current user's requests
        updates.put(currentUserPhone + "/friendRequests/" + requester.getPhone(), null);

        // Remove from requester's sent requests
        updates.put(requester.getPhone() + "/sentRequests/" + currentUserPhone, null);

        // Add to current user's friends
        updates.put(currentUserPhone + "/friends/" + requester.getPhone(), true);

        // Add to requester's friends
        updates.put(requester.getPhone() + "/friends/" + currentUserPhone, true);

        // Remove from local list FIRST for immediate UI update
        final int[] positionHolder = {-1};
        for (int i = 0; i < friendRequestsList.size(); i++) {
            if (friendRequestsList.get(i).getPhone().equals(requester.getPhone())) {
                positionHolder[0] = i;
                break;
            }
        }

        if (positionHolder[0] != -1) {
            friendRequestsList.remove(positionHolder[0]);
            requestsAdapter.notifyItemRemoved(positionHolder[0]);
        }

        usersRef.updateChildren(updates)
                .addOnSuccessListener(aVoid -> {
                    Toast.makeText(this, "Friend request accepted", Toast.LENGTH_SHORT).show();
                })
                .addOnFailureListener(e -> {
                    // If Firebase fails, add the item back
                    if (positionHolder[0] != -1) {
                        friendRequestsList.add(positionHolder[0], requester);
                        requestsAdapter.notifyItemInserted(positionHolder[0]);
                    }
                    Toast.makeText(this, "Failed to accept request", Toast.LENGTH_SHORT).show();
                });
    }

    private void rejectFriendRequest(User requester) {
        HashMap<String, Object> updates = new HashMap<>();

        // Remove from current user's requests
        updates.put(currentUserPhone + "/friendRequests/" + requester.getPhone(), null);

        // Remove from requester's sent requests
        updates.put(requester.getPhone() + "/sentRequests/" + currentUserPhone, null);

        // Remove from local list FIRST for immediate UI update
        final int[] positionHolder = {-1};
        for (int i = 0; i < friendRequestsList.size(); i++) {
            if (friendRequestsList.get(i).getPhone().equals(requester.getPhone())) {
                positionHolder[0] = i;
                break;
            }
        }

        if (positionHolder[0] != -1) {
            friendRequestsList.remove(positionHolder[0]);
            requestsAdapter.notifyItemRemoved(positionHolder[0]);
        }

        usersRef.updateChildren(updates)
                .addOnSuccessListener(aVoid -> {
                    Toast.makeText(this, "Friend request rejected", Toast.LENGTH_SHORT).show();
                })
                .addOnFailureListener(e -> {
                    // If Firebase fails, add the item back
                    if (positionHolder[0] != -1) {
                        friendRequestsList.add(positionHolder[0], requester);
                        requestsAdapter.notifyItemInserted(positionHolder[0]);
                    }
                    Toast.makeText(this, "Failed to reject request", Toast.LENGTH_SHORT).show();
                });
    }

    private void removeFriend(User friend) {
        HashMap<String, Object> updates = new HashMap<>();

        // Remove from current user's friends
        updates.put(currentUserPhone + "/friends/" + friend.getPhone(), null);

        // Remove from friend's friends list
        updates.put(friend.getPhone() + "/friends/" + currentUserPhone, null);

        // Remove from local list FIRST for immediate UI update
        final int[] positionHolder = {-1}; // Use an array to hold the position
        for (int i = 0; i < friendsList.size(); i++) {
            if (friendsList.get(i).getPhone().equals(friend.getPhone())) {
                positionHolder[0] = i;
                break;
            }
        }

        if (positionHolder[0] != -1) {
            friendsList.remove(positionHolder[0]);
            friendsAdapter.notifyItemRemoved(positionHolder[0]);
        }

        usersRef.updateChildren(updates)
                .addOnSuccessListener(aVoid -> {
                    Toast.makeText(this, "Friend removed successfully", Toast.LENGTH_SHORT).show();
                })
                .addOnFailureListener(e -> {
                    // If Firebase fails, add the item back
                    if (positionHolder[0] != -1) {
                        friendsList.add(positionHolder[0], friend);
                        friendsAdapter.notifyItemInserted(positionHolder[0]);
                    }
                    Toast.makeText(this, "Failed to remove friend: " + e.getMessage(), Toast.LENGTH_SHORT).show();
                });
    }

    // Adapter for friend requests
    private class FriendRequestsAdapter extends RecyclerView.Adapter<FriendRequestsAdapter.ViewHolder> {
        private List<User> requests;

        public FriendRequestsAdapter(List<User> requests) {
            this.requests = requests;
        }

        @NonNull
        @Override
        public ViewHolder onCreateViewHolder(@NonNull ViewGroup parent, int viewType) {
            View view = LayoutInflater.from(parent.getContext()).inflate(R.layout.item_friend_request, parent, false);
            return new ViewHolder(view);
        }

        @Override
        public void onBindViewHolder(@NonNull ViewHolder holder, int position) {
            User requester = requests.get(position);
            holder.usernameTv.setText(requester.getUsername());
            holder.phoneTv.setText(requester.getPhone());

            holder.acceptBtn.setOnClickListener(v -> acceptFriendRequest(requester));
            holder.rejectBtn.setOnClickListener(v -> rejectFriendRequest(requester));
        }

        @Override
        public int getItemCount() {
            return requests.size();
        }

        public class ViewHolder extends RecyclerView.ViewHolder {
            TextView usernameTv, phoneTv;
            Button acceptBtn, rejectBtn;

            public ViewHolder(@NonNull View itemView) {
                super(itemView);
                usernameTv = itemView.findViewById(R.id.usernameTv);
                phoneTv = itemView.findViewById(R.id.phoneTv);
                acceptBtn = itemView.findViewById(R.id.acceptBtn);
                rejectBtn = itemView.findViewById(R.id.rejectBtn);
            }
        }
    }

    // Adapter for friends list with remove functionality
    private class FriendsAdapter extends RecyclerView.Adapter<FriendsAdapter.ViewHolder> {
        private List<User> friends;

        public FriendsAdapter(List<User> friends) {
            this.friends = friends;
        }

        @NonNull
        @Override
        public ViewHolder onCreateViewHolder(@NonNull ViewGroup parent, int viewType) {
            View view = LayoutInflater.from(parent.getContext()).inflate(R.layout.item_friend, parent, false);
            return new ViewHolder(view);
        }

        @Override
        public void onBindViewHolder(@NonNull ViewHolder holder, int position) {
            User friend = friends.get(position);
            holder.usernameTv.setText(friend.getUsername());
            holder.phoneTv.setText(friend.getPhone());

            // Add remove friend functionality - pass only the friend object
            holder.removeBtn.setOnClickListener(v -> {
                new androidx.appcompat.app.AlertDialog.Builder(Friend.this)
                        .setTitle("Remove Friend")
                        .setMessage("Are you sure you want to remove " + friend.getUsername() + " from your friends?")
                        .setPositiveButton("Yes", (dialog, which) -> removeFriend(friend))
                        .setNegativeButton("No", null)
                        .show();
            });
        }

        @Override
        public int getItemCount() {
            return friends.size();
        }

        public class ViewHolder extends RecyclerView.ViewHolder {
            TextView usernameTv, phoneTv;
            Button removeBtn;

            public ViewHolder(@NonNull View itemView) {
                super(itemView);
                usernameTv = itemView.findViewById(R.id.usernameTv);
                phoneTv = itemView.findViewById(R.id.phoneTv);
                removeBtn = itemView.findViewById(R.id.removeBtn);
            }
        }
    }
}