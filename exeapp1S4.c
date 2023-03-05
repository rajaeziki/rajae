#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
 typedef struct {
float solde;
int num;
char Cin[10];
struct compte *suivant;
}compte;
// AJOUT 
 compte *ajout(compte*tet){
 	 compte *c;
 	 // allocation
 	 c=(compte*)malloc(sizeof(compte));
 	 // ajout des doneee
 	 printf("donner les donner ");
 	 scanf("%d%f%s",&c->num,&c->solde,c->Cin);
 	 // chainnage 
 	 c->suivant=tet;
 	 tet=c;
 	 return tet; 
 }
 //qff
 void affichage (compte*tet){
 	compte*tmp=tet;
 	while(tmp!=NULL){
 		printf("les numest %d\t solde est %f\t le cin est %s\n",tmp->num ,tmp->solde,tmp->Cin);
 		tmp=tmp->suivant ; 
	 }
 }
 //augaff
 void augsolde(compte*rep){
 	compte *tmp=rep;
 	while(tmp!=NULL){
 		tmp->solde=tmp->solde+((tmp->solde)*20)/100;
 		tmp=tmp->suivant;	
	 }
 }
 //solde plus eleve
 float SoldeElv(compte*rep){
 	compte *tmp=rep, *r;
 	float max=tmp->solde;
 	while(tmp!=NULL){
 		r=tmp->suivant;
 		if(max<=r->solde){
 			max=r->solde;
		 }
 		tmp=tmp->suivant;	
	 }
	 return max;
 }
 
int main(){
	int n,i; 
	float se;
	compte *tet=NULL;
	// ajout 
	printf("donner combien de compte a ajoutee\t");
	scanf("%d",&n);
	for(i=0;i<n;i++){
	tet=ajout(tet);
	
	}
	// affichage 
	affichage (tet);
	//qugmentqtion sole pqr 20%
	augsolde(tet);
	//nouv aff
	printf("nouv aff qpres qugmentqtion\n")
	affichage (tet);
	// solde plus eleve
	se=SoldeElv(tet);
	printf("solde le plus eleve est %.2f\n",se);
	
	getch();
}
