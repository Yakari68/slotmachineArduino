/* Wait A Second (c) Owen TRAN - 2025
 *  
 *  v1.0
 *  
 * Timer non bloquant pour boucle while dans
 * le cadre du projet de machine à sous du
 * Gala 2026 de l'ENSISA
 * 
 * Utilisation:
 * 
  
// Déclaration de l'objet:
WAS was;

void setup(){}
void loop(){
  // Instructions...
  was.setDuration(15000); // Durée en ms
  // Instructions...
  was.waitASecond(); // Démarrage du timer
  while(was.isActive()){  // Usage attendu de l'objet WAS
    was.waitASecond(); // Met à jour la variable isRunning de l'objet WAS
    // Instructions à faire durant le timer
    if(condition)was.reset(); // La condition met fin au timer prématurément
  }
  // Instructions... 
  // On peut se reservir de l'objet en changeant la valeur de la durée
}
 * 
 * 
 */

class WAS{
  private:
    long offset;
    bool isRunning;
    long duration;
  public:
    bool isActive(){return isRunning;}
    void reset(){
      isRunning = false;
    }
    void setDuration(long d){reset();duration = d;}
    void waitASecond(){
      if(!isRunning){
        offset = millis();
        isRunning = true;
      }else if(millis()-offset>duration) isRunning = false;
    }
};
