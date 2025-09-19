package com.example.quickaid.crimes;

import java.util.HashMap;

public class CrimeReport {
    private String description;
    private String place;
    private String time;
    private String reporterPhone;
    private String reporterName;
    private long timestamp;

    public CrimeReport() {
        // Default constructor required for Firebase
    }

    public CrimeReport(String description, String place, String time, String reporterPhone, String reporterName) {
        this.description = description;
        this.place = place;
        this.time = time;
        this.reporterPhone = reporterPhone;
        this.reporterName = reporterName;
        this.timestamp = System.currentTimeMillis();
    }

    // Getters and setters
    public String getDescription() { return description; }
    public void setDescription(String description) { this.description = description; }

    public String getPlace() { return place; }
    public void setPlace(String place) { this.place = place; }

    public String getTime() { return time; }
    public void setTime(String time) { this.time = time; }

    public String getReporterPhone() { return reporterPhone; }
    public void setReporterPhone(String reporterPhone) { this.reporterPhone = reporterPhone; }

    public String getReporterName() { return reporterName; }
    public void setReporterName(String reporterName) { this.reporterName = reporterName; }

    public long getTimestamp() { return timestamp; }
    public void setTimestamp(long timestamp) { this.timestamp = timestamp; }

    public HashMap<String, Object> toMap() {
        HashMap<String, Object> map = new HashMap<>();
        map.put("description", description);
        map.put("place", place);
        map.put("time", time);
        map.put("reporterPhone", reporterPhone);
        map.put("reporterName", reporterName);
        map.put("timestamp", timestamp);
        return map;
    }
}