package hello;

import java.util.Scanner;

public class hello {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        String fellow = "World";
        System.out.printf("Hello %s\n", fellow);
        //while (fellow != "exit") {
        while (!(fellow.equals("exit"))) {
            System.out.printf("Introduce yourself: ");
            fellow = s.nextLine();
            System.out.printf("Hello %s\n", fellow);
        }
        s.close();
    }
}
/*
Program nie kończy się podczas wpisania exit.
Symbol == w Javie porównuje referencje, a nie zawartość.
*/