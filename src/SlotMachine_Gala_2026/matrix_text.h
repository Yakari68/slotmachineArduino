WAS was;

void startScreen(){
  matrix->setTextColor(matrix->Color333(7,7,7));
  matrix->setCursor(3, 5);
  matrix->print('S');
  matrix->print('l');  
  matrix->print('o');  
  matrix->print('t');
  matrix->setCursor(3, 16);
  matrix->print('M');
  matrix->print('a');  
  matrix->print('c');  
  matrix->print('h');
  matrix->print('i');
  matrix->print('n');  
  matrix->print('e');
  displaySymbol(50,9,10);
  matrix->show();
  delay(2000);
  matrix->clearmatrix();
  matrix->setCursor(3, 2);
  matrix->print('G');
  matrix->print('a');  
  matrix->print('l');  
  matrix->print('a');
  matrix->setCursor(3, 13);
  matrix->print('E');
  matrix->print('N');  
  matrix->print('S');  
  matrix->print('I');
  matrix->print('S');
  matrix->print('A');
  matrix->setCursor(3, 24);
  matrix->print('2');
  matrix->print('0');  
  matrix->print('2');  
  matrix->print('6');
  displaySymbol(50,9,10);
  matrix->show();
  delay(2000);
  matrix->clearmatrix();
}

// *****
// BIENVENUE
// *****

void showWelcomeText(){
  matrix->setTextColor(matrix->Color333(7,7,0));

  //matrix->fillRect(1,1,26,9, matrix->Color333(0,0,0));

  
  was.setDuration(random(400,800));
  was.waitASecond();
  while(was.isActive()){
    was.waitASecond();
    if(lever)break;
  }
     
  matrix->fillRect(1,1,24,9, matrix->Color333(0,0,0));
  matrix->setCursor(2, 2);
  matrix->print('P');
  matrix->print('u');  
  matrix->print('l');  
  matrix->print('l');
  
  matrix->show();
  was.setDuration(random(400,800));
  was.waitASecond();
  while(was.isActive()){
    was.waitASecond();
    if(lever)break;
  }
  
  matrix->fillRect(20,11,19,9, matrix->Color333(0,0,0));
  matrix->setCursor(21, 12);
  // Milieu ligne 1, au centre
  matrix->print('t');  
  matrix->print('h');  
  matrix->print('e');
  
  matrix->show();
  was.setDuration(random(400,800));
  was.waitASecond();
  while(was.isActive()){
    was.waitASecond();
    if(lever)break;
  }
  
  matrix->fillRect(32,21,31,9, matrix->Color333(0,0,0));
  matrix->setCursor(33, 22);
  matrix->print('l');
  matrix->print('e');  
  matrix->print('v');
  matrix->print('e');  
  matrix->print('r');

  
  matrix->show();
  was.setDuration(random(1400,2900));
  was.waitASecond();
  while(was.isActive()){
    was.waitASecond();
    if(lever)break;
  }

}

void welcomeScreen(){
  displaySymbol(52,2,11);
  displaySymbol(2,21,12);
  matrix->show();
  showWelcomeText();
  matrix->clearmatrix();
}

// *****
// SÉLECTION DES SYMBOLES
// *****

WAS was2;

void randomScrolling(){
  // Tourne pendant 3 secondes, puis arrête les reels
  // un par un à 0.6 s d'intervalle, et le dernier à 1 s
  // puis attend 1.5 s.
  matrix->clearmatrix();
  was.setDuration(3000);
  was.waitASecond();
  while(was.isActive()){
    for(int j=0;j<5;j++){
      for(int i=0;i<3;i++){
        displaySymbol(tx[j], ty[i], random(0,10));
      }
      was.waitASecond();
      if(!was.isActive())break;
      matrix->show();
    }
    was2.setDuration(400);
    was2.waitASecond();
    while(was2.isActive()){
      was2.waitASecond();
      if(!was.isActive())break;
    }
    was.waitASecond();
  }
  matrix->clearmatrix();
  for(int j=0;j<4;j++){
    was.setDuration(500);
    was.waitASecond();
    while(was.isActive())was.waitASecond();
    for(int i=0;i<3;i++){
      displaySymbol(tx[j], ty[i], symbols[i][j]);
    }
    matrix->show();
  }
  was.setDuration(1000);
  was.waitASecond();
  while(was.isActive())was.waitASecond();
  for(int i=0;i<3;i++){
    displaySymbol(tx[4], ty[i], symbols[i][4]);
  }
  matrix->show();
  was.setDuration(2000);
  was.waitASecond();
  while(was.isActive())was.waitASecond();
}

void writePaylines(){
  for(int row=0; row<3; row++){
    for(int col=0; col<5; col++){
      if(resultsSymbols[row][col]==-1){
        // Efface visuellement le symbole hors payline
        matrix->fillRect(tx[col], ty[row], 10, 10, matrix->Color333(0,0,0));
      }
    }
  }

  matrix->show();
  was.setDuration(3000);
  was.waitASecond();
  while(was.isActive())was.waitASecond();
}

void spinningScreen(){
  check();
  randomScrolling();
}

// *****
// VICTOIRE ?
// *****

void showGains(){
  matrix->clearmatrix();
  matrix->setTextColor(matrix->Color333(7,7,0));
  matrix->setCursor(23, 4);
  matrix->print('Y');
  matrix->print('O');  
  matrix->print('U');
  matrix->setCursor(15, 15);
  matrix->print('W');
  matrix->print('I');  
  matrix->print('N');
  matrix->print('!');
  matrix->print('!');
  matrix->print('!');
  matrix->show();
  was.setDuration(2000);
  was.waitASecond();
  while(was.isActive())was.waitASecond();
  matrix->clearmatrix();
  matrix->setTextColor(matrix->Color333(7,7,0));
  matrix->setCursor(17, 4);
  matrix->print('G');
  matrix->print('A');  
  matrix->print('I');  
  matrix->print('N');  
  matrix->print('S');
  matrix->setCursor(29, 15);
  matrix->print(gains);
  matrix->show();
  was.setDuration(4000);
  was.waitASecond();
  while(was.isActive())was.waitASecond();
}

void giveGains(){
  // Donne les gains
  
}

void tryAgain(){
  // Affiche le message d'échec, et incite
  // (mais pas trop!) à rejouer

  
  matrix->clearmatrix();
  matrix->setTextColor(matrix->Color333(7,7,0));
  matrix->setCursor(23, 4);
  matrix->print('Y');
  matrix->print('o');  
  matrix->print('u');
  matrix->setCursor(11, 15);
  matrix->print('l');
  matrix->print('o');  
  matrix->print('s');
  matrix->print('t');
  matrix->print('.');
  matrix->print('.');
  matrix->print('.');
  matrix->show();
  was.setDuration(3000);
  was.waitASecond();
  while(was.isActive())was.waitASecond();
}

void resultsScreen(){
  if(victory){
    writePaylines();
    showGains();
    giveGains();
  }else tryAgain();
}
