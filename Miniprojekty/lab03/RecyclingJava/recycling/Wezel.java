package recycling;

import java.util.ArrayList;
import java.util.Scanner;

public class Wezel {
    @Deprecated
    @Override

    

    protected void finalize() throws Throwable {
    System.out.println("Finalizowanie obiektu");
    super.finalize();
    }

    private ArrayList<Wezel> polaczenia = new ArrayList<>();

    public void dodajPolaczenie(Wezel w) {
        
    }
    
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        for(int i = 0; i <= 1000000; i++) {
            Wezel w1 = new Wezel ( ) ;
            Wezel w2 = new Wezel ( ) ;
            w1.dodajPolaczenie(w2);
            w2.dodajPolaczenie(w1);
        }
        s.nextLine();
        s.close();

    }
}

/*
5.  Brak odpowiedzi na konsoli.
7.  Zostało wypisane na terminal wielokrotnie "Finalizowanie obiektu". Wynika to z tego, że po pewnej ilości iternacji został uruchomiony garbage collector
    i została uruchomiona funkcja finalize().
11. Wynika to z tego, że te odwołania nie są nigdzie zapisywane.
12. Zwykły Array nie jest dynamiczny, jego wielkość jest stała, przez co nie można dodać nowego elementu (trzeba utworzyć tablice na nowo).
    W ArrayList można łatwo dodawać nowe elementy.

*/