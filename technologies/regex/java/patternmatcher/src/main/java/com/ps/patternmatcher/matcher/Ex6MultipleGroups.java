package com.ps.patternmatcher.matcher;

import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class Ex6MultipleGroups {
    public static void main(String[] args) {
        // there can be muktiple groups in a regex
        // groupNo is determined by the position of opening parentheses
        // groupNo = 1 : (John)
        // groupNo = 2 : (.+?)
        String text = "John writes about this, and John Doe writes about that, and John Wayne writes about everything.";
        String regex = "(John) (.+?) ";

        Pattern pattern = Pattern.compile(regex);
        Matcher matcher = pattern.matcher(text);

        while(matcher.find()) {
            System.out.println("found: " + matcher.group(1) + " " + matcher.group(2));
        }
    }
}
