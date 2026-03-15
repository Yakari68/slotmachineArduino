/*
 * MACHINE DE CASINO - ENSISA GALA 2026
 * Auteur : Owen TRAN, 1A ASE
 * 
 * Ce programme gère une machine de casino développée dans le cadre
 * du gala annuel de l'ENSISA. Aucune mise n'est nécessaire pour jouer.
 * Le gain proposé est un jeton donnant droit à une boisson gratuite.
 * 
 * REQUIS:
 * RGBMatrixPanel.h     Gestion de l'écran
 * 
 * INCLUS (normalement):
 * images.h             Contient les images
 * was.h                Timer non bloquant sur base de boucle while
 * pile.h               Structure pile 
 * 
 *  Distribution des symboles par reel:
 *  
 *  0 J♠ : 4
 *  1 J♥ : 4
 *  2 Q♠ : 4
 *  3 Q♥ : 4
 *  4 K♠ : 3
 *  5 K♥ : 3
 *  6 A♠ : 2
 *  7 A♥ : 2
 *  8 Wild (W) (Joker) : 2
 *  9 Scatter (S) (Jeton casino) : 2
 */

#include "was.h"
#include <RGBmatrixPanel.h>

#define CLK 11
#define OE   9
#define LAT 10
#define A   A0
#define B   A1
#define C   A2
#define D   A3

RGBmatrixPanel *matrix = new RGBmatrixPanel(A, B, C, D, CLK, LAT, OE, true, 64);

#define clearmatrix()      fillScreen(0) // Définit la fonction matrix->clearmatrix() pour effacer la matrice
#define show()         swapBuffers(true) // Définit la fonction matrix->show() raffraichit la matrice.



//--------------------------//
//          LEVIER          //
//--------------------------//
bool victory;
bool lever = false; // FAUX quand le levier est au repos
bool inGame = false; // FAUX tant que la partie n'a pas commencé
const unsigned int pinLever = 2; // Pin levier
int gains;

void leverInterruptor(){
  // Interruption du levier: il passe à TRUE quand on le tire
  if(!inGame)lever = true;
}

#include "pile.h"
#include "reels_and_random_logic.h"
#include "images.h"
#include "matrix_text.h"

void setup() {
  //Serial.begin(9600);
  matrix->begin();
  initPile(&winningPL);
  initPile(&winningSymbols);
  randomSeed(analogRead(A7)*millis());
  attachInterrupt(digitalPinToInterrupt(pinLever),leverInterruptor,FALLING);
  startScreen();
}

void loop() {
  gains=0;
  matrix->clearmatrix();
  inGame=false;
  victory=false;
  initPile(&winningPL);
  initPile(&winningSymbols);
  while(!lever)welcomeScreen();
  randomSeed(analogRead(A7)*millis());
  inGame=true;
  lever=false;
  spinningScreen();
  resultsScreen();
}
