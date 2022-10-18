package com.ps.patternmatcher.pattern;

import java.util.regex.Pattern;

public class Ex2Compile {
    public static void main(String[] args) {
        // String text = "Is it okay? This is the text to be searched. THIS IS IT!";
        String regex = ".*is.*";

        // Pattern.compile() is used if you need to match for multiple occurrences 
        // or just need non-default settings
        Pattern.compile(regex, Pattern.CASE_INSENSITIVE | Pattern.MULTILINE);
    }
}
