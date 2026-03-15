struct SPile{
  int values[55];
  int top;
};
typedef struct SPile Pile;

void initPile(Pile * p){
  p->top=-1;
}

void push(Pile * p,int v){
  p->values[p->top+1]=v;
  p->top++;
}

int getTop(Pile *p){
  if(p->top==-1) return NULL;
  return p->values[p->top];
}

int len(Pile *p){
  return p->top+1;
}

void pop(Pile * p){
  p->top--;
}

void printPile(Pile *p){
  while(getTop(p)!=NULL){
    Serial.print(len(p));
    Serial.print("   ");
    Serial.print(getTop(p));
    Serial.println();
    pop(p);
  }
}
