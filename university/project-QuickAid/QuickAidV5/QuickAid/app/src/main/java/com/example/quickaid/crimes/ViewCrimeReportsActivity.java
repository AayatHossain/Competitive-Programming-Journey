package com.example.quickaid.crimes;

import android.os.Bundle;
import android.widget.Toast;
import androidx.annotation.NonNull;
import androidx.appcompat.app.AppCompatActivity;
import androidx.recyclerview.widget.LinearLayoutManager;
import androidx.recyclerview.widget.RecyclerView;
import com.example.quickaid.R;
import com.example.quickaid.crimes.CrimeReport;
import com.google.firebase.database.DataSnapshot;
import com.google.firebase.database.DatabaseError;
import com.google.firebase.database.DatabaseReference;
import com.google.firebase.database.FirebaseDatabase;
import com.google.firebase.database.ValueEventListener;
import java.util.ArrayList;
import java.util.List;

public class ViewCrimeReportsActivity extends AppCompatActivity {

    private RecyclerView reportsRecyclerView;
    private DatabaseReference crimeReportsRef;
    private CrimeReportsAdapter reportsAdapter;
    private List<CrimeReport> crimeReportsList;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_view_crime_reports);

        crimeReportsRef = FirebaseDatabase.getInstance().getReference("CrimeReports");

        initializeViews();
        loadCrimeReports();
    }

    private void initializeViews() {
        reportsRecyclerView = findViewById(R.id.reportsRecyclerView);
        crimeReportsList = new ArrayList<>();
        reportsAdapter = new CrimeReportsAdapter(crimeReportsList);

        reportsRecyclerView.setLayoutManager(new LinearLayoutManager(this));
        reportsRecyclerView.setAdapter(reportsAdapter);
    }

    private void loadCrimeReports() {
        crimeReportsRef.orderByChild("timestamp") // Sort by timestamp (newest first)
                .addValueEventListener(new ValueEventListener() {
                    @Override
                    public void onDataChange(@NonNull DataSnapshot snapshot) {
                        crimeReportsList.clear();
                        for (DataSnapshot reportSnapshot : snapshot.getChildren()) {
                            CrimeReport crimeReport = reportSnapshot.getValue(CrimeReport.class);
                            if (crimeReport != null) {
                                crimeReportsList.add(0, crimeReport); // Add to beginning for newest first
                            }
                        }
                        reportsAdapter.notifyDataSetChanged();

                        if (crimeReportsList.isEmpty()) {
                            Toast.makeText(ViewCrimeReportsActivity.this, "No crime reports available", Toast.LENGTH_SHORT).show();
                        }
                    }

                    @Override
                    public void onCancelled(@NonNull DatabaseError error) {
                        Toast.makeText(ViewCrimeReportsActivity.this, "Error loading reports: " + error.getMessage(), Toast.LENGTH_SHORT).show();
                    }
                });
    }
}