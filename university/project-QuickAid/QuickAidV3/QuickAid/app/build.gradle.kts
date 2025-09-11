plugins {
//    alias(libs.plugins.android.application)

    //new
    id("com.android.application")
    id("org.jetbrains.kotlin.android")
    id("com.google.gms.google-services")
    //new
}

android {
    namespace = "com.example.quickaid"
    compileSdk = 36

    defaultConfig {
        applicationId = "com.example.quickaid"
        minSdk = 24
        targetSdk = 36
        versionCode = 1
        versionName = "1.0"

        testInstrumentationRunner = "androidx.test.runner.AndroidJUnitRunner"
    }

    buildTypes {
        release {
            isMinifyEnabled = false
            proguardFiles(
                getDefaultProguardFile("proguard-android-optimize.txt"),
                "proguard-rules.pro"
            )
        }
    }
    compileOptions {
        sourceCompatibility = JavaVersion.VERSION_11
        targetCompatibility = JavaVersion.VERSION_11
    }
}

dependencies {

    implementation(libs.appcompat)
    implementation(libs.material)
    implementation(libs.activity)
    implementation(libs.constraintlayout)
    testImplementation(libs.junit)
    androidTestImplementation(libs.ext.junit)
    androidTestImplementation(libs.espresso.core)


    //new
    // Firebase BoM (Bill of Materials) – keep all Firebase libs in sync
    implementation(platform("com.google.firebase:firebase-bom:34.1.0"))

    // Firebase Realtime Database
    implementation("com.google.firebase:firebase-database")

    // (Optional) Firebase Authentication
    implementation("com.google.firebase:firebase-auth")
    //new


    //map
    implementation("org.osmdroid:osmdroid-android:6.1.16")
    implementation("com.karumi:dexter:6.2.3")
    implementation("com.squareup.retrofit2:retrofit:2.9.0")
    implementation("com.squareup.retrofit2:converter-gson:2.9.0")
    implementation("androidx.preference:preference:1.2.1")
    //map


    //material buttons
    implementation("com.google.android.material:material:1.9.0")


}