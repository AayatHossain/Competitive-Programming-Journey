package com.example.quickaid.pages;

import android.os.Bundle;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.EditText;
import android.widget.RadioButton;
import android.widget.RadioGroup;
import android.widget.Spinner;
import android.widget.TextView;
import androidx.appcompat.app.AppCompatActivity;
import com.example.quickaid.R;
import java.text.DecimalFormat;

public class health_trackers extends AppCompatActivity {

    private EditText weightEditText, heightEditText, ageEditText;
    private RadioGroup genderRadioGroup;
    private RadioButton maleRadioButton, femaleRadioButton;
    private Spinner activityLevelSpinner;
    private TextView bmiResultTextView, bmiCategoryTextView;
    private TextView bmrResultTextView;
    private TextView ibwResultTextView;
    private TextView hydrationResultTextView;
    private Button calculateButton;

    private String selectedGender = "Male";
    private double activityLevel = 1.2;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.tracker_design);


        initializeViews();


        setupSpinner();


        calculateButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                calculateAllMetrics();
            }
        });


        genderRadioGroup.setOnCheckedChangeListener(new RadioGroup.OnCheckedChangeListener() {
            @Override
            public void onCheckedChanged(RadioGroup group, int checkedId) {
                if (checkedId == R.id.maleRadioButton) {
                    selectedGender = "Male";
                } else if (checkedId == R.id.femaleRadioButton) {
                    selectedGender = "Female";
                }
            }
        });
    }

    private void initializeViews() {
        weightEditText = findViewById(R.id.weightEditText);
        heightEditText = findViewById(R.id.heightEditText);
        ageEditText = findViewById(R.id.ageEditText);

        genderRadioGroup = findViewById(R.id.genderRadioGroup);
        maleRadioButton = findViewById(R.id.maleRadioButton);
        femaleRadioButton = findViewById(R.id.femaleRadioButton);

        activityLevelSpinner = findViewById(R.id.activityLevelSpinner);

        bmiResultTextView = findViewById(R.id.bmiResultTextView);
        bmiCategoryTextView = findViewById(R.id.bmiCategoryTextView);
        bmrResultTextView = findViewById(R.id.bmrResultTextView);
        ibwResultTextView = findViewById(R.id.ibwResultTextView);
        hydrationResultTextView = findViewById(R.id.hydrationResultTextView);

        calculateButton = findViewById(R.id.calculateButton);
    }

    private void setupSpinner() {
        ArrayAdapter<CharSequence> adapter = ArrayAdapter.createFromResource(
                this,
                R.array.activity_levels,
                android.R.layout.simple_spinner_item
        );
        adapter.setDropDownViewResource(android.R.layout.simple_spinner_dropdown_item);
        activityLevelSpinner.setAdapter(adapter);

        activityLevelSpinner.setOnItemSelectedListener(new AdapterView.OnItemSelectedListener() {
            @Override
            public void onItemSelected(AdapterView<?> parent, View view, int position, long id) {

                switch (position) {
                    case 0: activityLevel = 1.2; break;    // Sedentary
                    case 1: activityLevel = 1.375; break;  // Light
                    case 2: activityLevel = 1.55; break;   // Moderate
                    case 3: activityLevel = 1.725; break;  // Active
                    case 4: activityLevel = 1.9; break;    // Very Active
                }
            }

            @Override
            public void onNothingSelected(AdapterView<?> parent) {
                activityLevel = 1.2;
            }
        });
    }

    private void calculateAllMetrics() {

        String weightStr = weightEditText.getText().toString();
        String heightStr = heightEditText.getText().toString();
        String ageStr = ageEditText.getText().toString();


        if (weightStr.isEmpty() || heightStr.isEmpty() || ageStr.isEmpty()) {
            clearResults();
            bmiCategoryTextView.setText("Please fill all fields");
            return;
        }

        try {
            double weight = Double.parseDouble(weightStr);
            double height = Double.parseDouble(heightStr);
            int age = Integer.parseInt(ageStr);


            calculateBMI(weight, height);
            calculateBMR(weight, height, age);
            calculateIBW(height);
            calculateHydration(weight);

        } catch (NumberFormatException e) {
            clearResults();
            bmiCategoryTextView.setText("Invalid input values");
        }
    }

    private void calculateBMI(double weight, double height) {

        double heightInMeters = height / 100;


        double bmi = weight / (heightInMeters * heightInMeters);


        DecimalFormat df = new DecimalFormat("#.#");
        bmiResultTextView.setText(df.format(bmi));


        String category;
        if (bmi < 18.5) {
            category = "Underweight";
        } else if (bmi < 25) {
            category = "Normal weight";
        } else if (bmi < 30) {
            category = "Overweight";
        } else {
            category = "Obese";
        }
        bmiCategoryTextView.setText(category);
    }

    private void calculateBMR(double weight, double height, int age) {
        double bmr;


        if (selectedGender.equals("Male")) {
            bmr = (10 * weight) + (6.25 * height) - (5 * age) + 5;
        } else {
            bmr = (10 * weight) + (6.25 * height) - (5 * age) - 161;
        }


        double tdee = bmr * activityLevel;

        DecimalFormat df = new DecimalFormat("#");
        bmrResultTextView.setText(df.format(tdee) + " kcal/day");
    }

    private void calculateIBW(double height) {
        double ibw;


        if (selectedGender.equals("Male")) {
            ibw = 50 + 0.9 * (height - 152);
        } else {
            ibw = 45.5 + 0.9 * (height - 152);
        }

        DecimalFormat df = new DecimalFormat("#.#");
        ibwResultTextView.setText(df.format(ibw) + " kg");
    }

    private void calculateHydration(double weight) {

        double hydration = weight * 35;

        DecimalFormat df = new DecimalFormat("#");
        hydrationResultTextView.setText(df.format(hydration) + " ml/day");
    }

    private void clearResults() {
        bmiResultTextView.setText("--");
        bmrResultTextView.setText("--");
        ibwResultTextView.setText("--");
        hydrationResultTextView.setText("--");
    }
}