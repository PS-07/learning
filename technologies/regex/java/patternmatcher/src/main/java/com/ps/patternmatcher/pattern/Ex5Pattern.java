package com.ps.patternmatcher.pattern;

import java.util.regex.Pattern;

public class Ex5Pattern {
    public static void main(String[] args) {
        String regex = "sep";
        Pattern pattern = Pattern.compile(regex);
        
        // Pattern.pattern() returns the String it was compiled from
        String getRegex = pattern.pattern();

        System.out.println("regex = " + getRegex);
    }
}
