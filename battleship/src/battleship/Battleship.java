/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package battleship;
import java.util.Scanner;
import java.lang.Math;

/**
 * @author chees
 */

public class Battleship {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        Client game = new Client();

        game.run();
    }  
}
class Client {
    public Scanner uIn = new Scanner(System.in);
    Map uMap = new Map(), cMap = new Map(), cMap2 = new Map();
    Player p1;
    AI c1;


    Client() {
        this.p1 = new Player();
        System.out.println("Welcome to Battleship! \nPlease select a difficulty (0-10): ");
        this.c1 = new AI(/*uIn.nextByte()*/(byte)10);
    }


    public void run() {
        byte sP = 0, sC = 0; 
        byte[] a = new byte[2];

        boardSetP();
        boardSetC();

        while (sP < 17 && sC < 17) {
            if (cMap.hit(a = p1.hit(cMap)) == 1) {
                sP++;
                cMap2.place(a[0], a[1]);
                cMap2.hit(a);
            } else {
                cMap2.place(a[0], a[1]);
            }

            sC += uMap.hit(c1.shipKill(uMap));
            System.out.println("Your guesses: ");
            cMap2.printMap();
            System.out.println("\nYour map:");
            uMap.printMap();
        }
        System.out.println((sP == 17) ? "P win" : "C win");
    }

    public void boardSetP() {
        for (int i = 0; i < 5; i++) {
            uMap.printMap();
            p1.placeShip(uMap);
        } 
        System.out.println("Your map:");
        uMap.printMap();
    }

    public void boardSetC(){
        for (int i = 0; i < 5; i++) {
            c1.placeShip(cMap);
        }
    }
}
class Map {
    char[][] map = {{'-', '-', '-', '-', '-', '-', '-', '-', '-', '-'},
                    {'-', '-', '-', '-', '-', '-', '-', '-', '-', '-'},
                    {'-', '-', '-', '-', '-', '-', '-', '-', '-', '-'},
                    {'-', '-', '-', '-', '-', '-', '-', '-', '-', '-'},
                    {'-', '-', '-', '-', '-', '-', '-', '-', '-', '-'},
                    {'-', '-', '-', '-', '-', '-', '-', '-', '-', '-'},
                    {'-', '-', '-', '-', '-', '-', '-', '-', '-', '-'},
                    {'-', '-', '-', '-', '-', '-', '-', '-', '-', '-'},
                    {'-', '-', '-', '-', '-', '-', '-', '-', '-', '-'},
                    {'-', '-', '-', '-', '-', '-', '-', '-', '-', '-'}};
    byte shipI = 0;
    byte[] shipL = {2, 3, 3, 4, 5};
    
    public void place(byte y, byte x) {
        // System.out.println(x + ", " + y);
        map[y][x] = (map[y][x] == 45) ? 'x' : map[y][x];
    }
    public byte hit(byte[] c) {
        if (map[c[0]][c[1]] == 120) { 
            map[c[0]][c[1]] = 'o'; 
            return 1; 
        }

        return 0;
    }

    public void printMap() {
        char[] hd = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
        System.out.printf("    1  2  3  4  5  6  7  8  9 10 \n");
        for (int i = 0; i < 10; i++) {
            System.out.printf("%2s ", hd[i]);
            for (int j = 0; j < 10; j++) {
                System.out.printf("%2s ", map[i][j]);
            } System.out.println();
        }
    }

    public void placeShip(byte[] loc) {
        switch (loc[2]) {
            case 0:
                for (int i = 0; i < shipL[shipI]; i++) {
                    place(loc[0], (byte) (loc[1] + i));
                } break;
            case 1:
                for (int i = 0; i < shipL[shipI]; i++) {
                    place((byte) (loc[0] + i), loc[1]);
                }
        }
    }

    public char[] loadMapH(byte[] loc, char[] container) {
        for (int i = 0; i < shipL[shipI]; i++)
            container[i] = map[loc[0]][loc[1] + i];

        return container;
    }

    public char[] loadMapV(byte[] loc, char[] container) {
        for (int i = 0; i < shipL[shipI]; i++)
            container[i] = map[loc[0] + i][loc[1]];

        return container;
    }

    public byte colDist(char[] container) {
        for (byte i = 0; i < shipL[shipI]; i++) {
            if (i > 0 && container[i] == 'x') {
                return i;
            } else if (i == 0 && container[i] == 'x') {
                return -1;
            }
        }

        return 0;
    }

    public byte[] sShip(byte[] loc) {
        char[] _pCache_ = new char[shipL[shipI]];
        byte[] except = {-1, -1, -1};
        byte d;
        switch (loc[2]) {
            case 0:
                if (loc[1] + shipL[shipI] >= 10) {
                    d = (byte) (loc[1] + shipL[shipI] - 10);
                    if((loc[1] -= /*shipL[shipI] -*/ d) >= 0)
                        return loc;
                    else
                        return except;
                } else {
                    _pCache_ = loadMapH(loc, _pCache_);
                    d = colDist(_pCache_);
                    if (d > 0) {
                        if((loc[1] -= /*shipL[shipI] -*/ d) >= 0)
                            return loc;
                        else
                            return except;
                    } else if (d == 0){ 
                        return loc; 
                    } else { 
                        return except; 
                    } 
                }
            case 1:
                if (loc[0] + shipL[shipI] >= 10) {
                    d = (byte) (loc[0] + shipL[shipI] - 10);
                    if((loc[0] -= /*shipL[shipI] -*/ d) >= 0)
                        return loc;
                    else
                        return except;
                } else {
                    _pCache_ = loadMapV(loc, _pCache_);
                    d = colDist(_pCache_);
                    if (d > 0) {
                        if((loc[0] -= /*shipL[shipI] -*/- d) >= 0)
                            return loc;
                        else
                            return except;
                    } else if (d == 0){ 
                        return loc; 
                    } else { 
                        return except; 
                    }
                }
        } return except;
    }

    public boolean canSet(byte a) {
        return !(a > 9 || a < 0);
    }

    public boolean canPlace(byte[] in) {
        return (in[2] >= 0);
    }
}
class Player {
    public byte y, x, d;
    Scanner uIn = new Scanner(System.in);

    public byte[] getCoords(Map uMap) {
        boolean isValid = true;
        char t;

        do {
            System.out.println("What row is the ship on (A-H)? ");
            y = (byte) (uIn.next().toUpperCase().charAt(0) - 65);
            isValid = uMap.canSet(y);
        } while (!isValid);

        do {
            System.out.println("What column is the ship on (1-10)? ");
            x = (byte) (uIn.nextByte() - 1);
            isValid = uMap.canSet(x);
        } while (!isValid);

        do {
            System.out.println("What direction does it face (H/V)? ");
            d = ((t = uIn.next().toUpperCase().charAt(0)) - 64) == 8 ? 
                (byte) 0 : t - 64 == 22 ? (byte) 1 : -1; 
                /** horizontal = 0 vertical = 1 */
            isValid = uMap.canSet(d);
        } while (!isValid);

        byte[] loc = {y, x, d};

        return loc;      
    }

    public void placeShip(Map uMap) {
        boolean place = true;
        byte[] loc = new byte[3];
        do {
            loc = getCoords(uMap);
            if (place = uMap.canPlace(loc = uMap.sShip(loc))) {
                uMap.placeShip(loc);
                uMap.shipI++;
            }
        } while (!place);
    }

    public byte[] hit(Map cMap) {
        boolean isValid = true;

        do {
            System.out.println("What row is the ship on (A-H)? ");
            y = (byte) (uIn.next().toUpperCase().charAt(0) - 65);
            isValid = cMap.canSet(y);
        } while (!isValid);

        do {
            System.out.println("What column is the ship on (1-10)? ");
            x = (byte) (uIn.nextByte() - 1);
            isValid = cMap.canSet(x);
        } while (!isValid);

        byte[] out = {y, x};
        return out;

    }
}
class AI {
    public byte dif;
    public byte[] lLoc = {-1, -1};
    public boolean[] dLock = {true, true};
    // dlock[1] == true == h false = v  

    AI (byte dif) {
        this.dif = dif;
    }

    public byte[] hit(Map uMap, byte[] loc) {
        byte[] out = {-1, -1};

        if (uMap.map[loc[0]][loc[1]] == 'x') {
            out[0] = loc[0];
            out[1] = loc[1];
        }

        return out;
    }
    
    public byte[] hit(Map uMap, char c) {
        byte[] out = {-1, -1};

        for (byte i = 0; i < 10; i++) {
            for (byte j = 0; j < 10; j++) {
                if (uMap.map[i][j] == c) {
                    out[0] = i;
                    out[1] = j;
                    return out;
                }
            }
        }
        return out;
    }

    public byte[] shipKill(Map uMap) {
        if (isHit()) {
            lLoc = (lLoc[0] == -1) ? hit(uMap, 'x') : lLoc;
            byte[][] dShip = {{lLoc[0], lLoc[1]}, {lLoc[0], lLoc[1]}, {lLoc[0], lLoc[1]}, {lLoc[0], lLoc[1]}, {lLoc[0], lLoc[1]}};
            /* E S W N */
            dShip[1][1]++;
            dShip[2][0]--;
            dShip[3][1]--;
            dShip[4][0]++;

            char[] eyes = new char[5];
            for (int i = 0; i < 5; i++) {
                eyes[i] = (uMap.canSet(dShip[i][0]) && uMap.canSet(dShip[i][1])) ? uMap.map[dShip[i][0]][dShip[i][1]] : '-';
            }

            for (int i = 0; i < 5; i++) {
                if (eyes[i] == 'x') {
                    if (dShip[i] == lLoc)
                        return dShip[i];
                    else if (dLock[0]) {
                        dLock[1] = i % 2 == 1;
                        lLoc = dShip[i];
                        dLock[0] = false;
                        return dShip[i];
                    } else {
                        if (dLock[1]) {
                            for (int j = 0; j < dShip.length >> 1; j++) {
                                if (eyes[2*j + 1] == 'x') {
                                    return dShip[2*j + 1];
                                }
                            }
                        } else {
                            for (int j = 0; j < dShip.length >> 1; j++) {
                                if (eyes[2*j] == 'x') {
                                    return dShip[2*j];
                                }
                            }
                        }
                    }
                }
            }

            lLoc[0] = -1; lLoc[1] = -1;
            dLock[0] = true;
            return shipKill(uMap);
        } else {
            return hit(uMap, '-');
        }
    }

    public boolean isHit() {
        return Math.random()* 10 <= dif;
    }

    public byte[] getCoords() {
        byte y = (byte) (Math.random()* 10);
        byte x = (byte) (Math.random()* 10);
        byte d = (byte) (Math.round(Math.random()));

        byte[] loc = {y, x, d};
        return loc;
    }

    public void placeShip(Map cMap) {
        boolean place = true;
        byte[] loc = new byte[3];

        do {
            loc = getCoords();
            if (place = cMap.canPlace(loc = cMap.sShip(loc))) {
                cMap.placeShip(loc);
                cMap.shipI++;
            }
        } while (!place);
    }
}