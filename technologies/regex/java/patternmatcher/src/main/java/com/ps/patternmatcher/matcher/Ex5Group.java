package com.ps.patternmatcher.matcher;

import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class Ex5Group {
    public static void main(String[] args) {
        // Groups are marked with parentheses in the regular expression
        // Matcher.group(int groupNo) returns the text that matched the subpart of the expression in a specific group
        // groupNo = 0 is always the whole regex
        // subsequent groups are numbered starting from 1
        String text = "John writes about this, and John writes about that, and John writes about everything.";
        String regex = "(John)";
        
        Pattern pattern = Pattern.compile(regex);
        Matcher matcher = pattern.matcher(text);

        while(matcher.find()) {
            System.out.println("found: " + matcher.group(1));
        }
    }
}
