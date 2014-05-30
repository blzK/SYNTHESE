#include <stdio.h>
#include <g3x.h>


typedef struct Shape
{
	G3Xpoint *vrtx;/*pointeurs vers les tableaux du vertex canonique*/
	G3Xvector *norm;/*pointeurs vers les tableaux du normales canonique*/
	G3Xcolor col; /*Couleur*/
  	int ID; /*type de forme*/
	double ambi, diff, spec, shine, alpha; /*materiau*/
	int pointNo; /*Nombre de vertex*/
	int normNo; /*Nombre de normales*/
	double ratio;
	int detail;
	GLuint* idVAO;
	GLuint* idVBOvrtx;
	GLuint* idVBOnorm;
} Shape;




//TEST tableaux de GLuint
GLuint * indicesVAO; 
GLuint * indicesVBO;

GLuint* requestIDVAO(Shape * str){

	printf("Entered requestVAO\n");
	GLuint temp;
	temp=(*indicesVAO);
	indicesVAO++;

	(*indicesVAO)=temp+1;

	//printf("TEST\n");
	str->idVAO=indicesVAO;
	return indicesVAO;

}

GLuint* requestIDVBO(Shape * str){

	printf("Entered requestVBO\n");
	GLuint temp;
	(temp)=(*indicesVBO); 
	indicesVBO++;
	(*indicesVBO)=temp+1;

///	printf("** %d\n",temp );
	str->idVBOvrtx=indicesVBO;
	indicesVBO++;
	str->idVBOnorm=indicesVBO+1;
	//printf("** %d\n",  str->idVBOnorm);
	return indicesVBO;

}


//TEST Vector


/*
std::vector<GLuint> indicesVAO; 
std::vector<GLuint> indicesVBO; 
*/
/*
GLuint requestIDVBO(Shape * str){
	printf("Entered requestVBO\n");
	indicesVBO.push_back(indicesVBO.back()+(GLuint)1);
	str->idVBOvrtx=indicesVBO.back();
	str->idVBOnorm=(GLuint)indicesVBO.back()+(GLuint)1;
	indicesVBO.push_back(indicesVBO.back()+(GLuint)1);
	return indicesVBO.back();

}
/*
GLuint requestIDVAO(Shape * str){
	printf("Entered requestVAO\n");
	indicesVAO.push_back(indicesVAO.back()+1);
	str->idVAO=indicesVAO.back();
	return indicesVAO.back();

}


GLuint requestIDVBO(Shape * str){
	printf("Entered requestVBO\n");
	indicesVAO.push_back(indicesVAO.back()+(GLuint)1);
	str->idVBOvrtx=indicesVBO.back();
	str->idVBOnorm=(GLuint)indicesVBO.back()+(GLuint)1;
	indicesVAO.push_back(indicesVAO.back()+(GLuint)1);
	return indicesVAO.back();

}
*/
