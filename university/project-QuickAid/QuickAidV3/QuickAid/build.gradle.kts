// Top-level build file where you can add configuration options common to all sub-projects/modules.
plugins {
//    alias(libs.plugins.android.application) apply false
    //new
    id("com.android.application") version "8.12.1" apply false
    id("com.android.library") version "8.12.1" apply false
    id("org.jetbrains.kotlin.android") version "2.2.10" apply false
    id("com.google.gms.google-services") version "4.4.3" apply false
    //new
}

buildscript {
    dependencies {
//        // Google Services plugin for Firebase
//        classpath("com.google.gms:google-services:4.4.3")
    }
}

//allprojects {
//    repositories {
//        google()
//        mavenCentral()
//    }
//}