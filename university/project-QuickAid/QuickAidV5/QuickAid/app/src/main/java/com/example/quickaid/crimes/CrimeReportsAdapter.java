package com.example.quickaid.crimes;

import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.TextView;
import androidx.annotation.NonNull;
import androidx.recyclerview.widget.RecyclerView;
import com.example.quickaid.R;
import com.example.quickaid.crimes.CrimeReport;
import java.text.SimpleDateFormat;
import java.util.List;
import java.util.Locale;

public class CrimeReportsAdapter extends RecyclerView.Adapter<CrimeReportsAdapter.ViewHolder> {

    private List<CrimeReport> crimeReports;

    public CrimeReportsAdapter(List<CrimeReport> crimeReports) {
        this.crimeReports = crimeReports;
    }

    @NonNull
    @Override
    public ViewHolder onCreateViewHolder(@NonNull ViewGroup parent, int viewType) {
        View view = LayoutInflater.from(parent.getContext()).inflate(R.layout.item_crime_report, parent, false);
        return new ViewHolder(view);
    }

    @Override
    public void onBindViewHolder(@NonNull ViewHolder holder, int position) {
        CrimeReport report = crimeReports.get(position);

        holder.descriptionTv.setText(report.getDescription());
        holder.placeTv.setText("Place: " + report.getPlace());
        holder.timeTv.setText("Time: " + report.getTime());
        holder.reporterTv.setText("Reported by: " + report.getReporterName());

        // Format timestamp
        SimpleDateFormat sdf = new SimpleDateFormat("MMM dd, yyyy HH:mm", Locale.getDefault());
        String date = sdf.format(report.getTimestamp());
        holder.dateTv.setText("Received: " + date);
    }

    @Override
    public int getItemCount() {
        return crimeReports.size();
    }

    public static class ViewHolder extends RecyclerView.ViewHolder {
        TextView descriptionTv, placeTv, timeTv, reporterTv, dateTv;

        public ViewHolder(@NonNull View itemView) {
            super(itemView);
            descriptionTv = itemView.findViewById(R.id.descriptionTv);
            placeTv = itemView.findViewById(R.id.placeTv);
            timeTv = itemView.findViewById(R.id.timeTv);
            reporterTv = itemView.findViewById(R.id.reporterTv);
            dateTv = itemView.findViewById(R.id.dateTv);
        }
    }
}