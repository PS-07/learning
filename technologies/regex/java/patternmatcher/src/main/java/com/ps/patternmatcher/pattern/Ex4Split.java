package com.ps.patternmatcher.pattern;

import java.util.regex.Pattern;

public class Ex4Split {
    public static void main(String[] args) {
        String text = "A sep Text sep With sep Many sep Separators";
        String regex = "sep";

        // Pattern.split() is use to split a text into 
        // array of Strings using regex (pattern) as deliminiator
        Pattern pattern = Pattern.compile(regex, Pattern.CASE_INSENSITIVE);
        String[] split = pattern.split(text);

        System.out.println("split.length = " + split.length);

        for (String element : split) {
            System.out.println("element = " + element);
        }
    }
}
