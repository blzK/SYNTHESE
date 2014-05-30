uint *testuint;
void InitSphereVAO(Shape * str){
	printf("Entering InitSphereVAO\n");
	//printf("%d\n",*(str->idVAO) );
	/*if(str->idVAO==0.){*/
	requestIDVAO(str);

	printf("%d\n",*(str->idVAO) );
	/*}*/
	/*if(str->idVBOvrtx==0. || str->idVBOnorm==0. ){*/
	requestIDVBO(str);
	printf("%d\n",*(str->idVBOvrtx) );
	printf("%d\n",*(str->idVBOnorm) );
	/*}*/

	/*Création du VAO*/
	glGenVertexArrays(1,(str->idVAO));
		//1 VAO avec ID

/*Activation du VAO*/
	glBindVertexArray(*(str->idVAO)); 
// Création de deux VBO
	printf("%d\n", str->idVAO);
	printf("in InitSphereVAO\n");

	glGenBuffers(1, str->idVBOvrtx);
	glGenBuffers(1, str->idVBOnorm);

	printf("%d\n", str->idVAO);
} 

void DrawSphereVAO(Shape * str){
	printf("Entered DrawSphereVAO\n");
	printf("%d\n", *(str->idVAO));
	printf("variables\n" );
	printf("%d\n",str->pointNo );	
	printf("%d\n",str->normNo );	
	printf("%d\n",*(str->idVBOnorm));
	printf("%d\n",*(str->idVBOvrtx));
/* Les sommets*/
	glBindBuffer(GL_ARRAY_BUFFER,*(str->idVBOvrtx));
	printf("test1\n" );
	//str-> vrtx est un pointeur de G3XPOINTS, ce que OPENGL ne sait traiter de base...
	glBufferData(GL_ARRAY_BUFFER,str->pointNo,str->vrtx,GL_STATIC_DRAW);
	glVertexAttribPointer(0, 4,GL_FLOAT,GL_FALSE, 0, 0);
	glEnableVertexAttribArray(0);

	printf("test2\n");
/* Les normales*/
	glBindBuffer(GL_ARRAY_BUFFER,*(str->idVBOnorm));
	glBufferData(GL_ARRAY_BUFFER,str->normNo,str->norm,GL_STATIC_DRAW);
	glVertexAttribPointer(1, 4,GL_FLOAT,GL_FALSE, 0, 0);
	glEnableVertexAttribArray(1);
/* Arrêt de la sauvegarde du VAO*/
	printf("test3\n");


	//lien VAO
	printf("%d\n",str->idVAO);
	glBindVertexArray(*(str->idVAO));
	printf("test4\n");
	glDrawArrays(GL_QUADS,0,str->pointNo);
//Arret VAO
	printf("test5\n");

	glBindVertexArray(*(str->idVAO));
	printf("test6\n");
}

void OrderUnboxSPhere(){
	
}



Shape * InitializeSphere(Shape * str){

	int i,j;
	double a=2*PI/N;
	double b=PI/P;
	str->pointNo=N*P;
	str->normNo=N*P;

	str->vrtx=(G3Xpoint*)malloc(N*P*sizeof(G3Xpoint));
	str->norm=(G3Xvector*)malloc(N*P*sizeof(G3Xvector));
	/*memset(str->vrtx, 0,N*P*sizeof(G3Xpoint));
	memset(str->norm, 0,N*P*sizeof(G3Xvector));*/ 
	G3Xvector *vn=str->norm;
	G3Xpoint *vt=str->vrtx;

	for(i=0;i<N;i++) 
	{

		for (j=0;j<P;j++)
		{
			(*vt)[0]=cos(i*a)*sin(j*b);
			(*vt)[1]=sin(i*a)*sin(j*b);
			(*vt)[2]=cos(j*b);

/*normale sphere*/

			(*vn)[0]=cos(i*a)*sin(j*b);
			(*vn)[1]=sin(i*a)*sin(j*b);
			(*vn)[2]=cos(j*b);

			vn++;
			vt++;
		}
	}

	InitSphereVAO(str);
	return str;
}


/*std::vector<unsigned int> indicesVBO; 


InitIndices(){

	for (int i = 0; i < 50; ++i)
	{
		indicesVAO.push_back(i);
	}
		for (int i = 0; i < 100; ++i)
	{
		indicesVBO.push_back(i);
	}
}*/


	void DrawSphere(Shape * str){


		str->pointNo=N*P;

		int i,j,k,N2,P2;
		i=0;
		j=0;
		k=0;

		int stepn=N/n; int stepp=P/p;

	/*SQUELETTE SPHERE*/
	/*glBegin(GL_POINTS);

	for(i=0;i<N-stepn;i+=stepn){

		for(j=0;j<P-stepp;j+=stepp){
			k=i*P+j;

			/*printf("\n %f %f %f !\n",str->vrtx[k][0],str->vrtx[k][1], str->vrtx[k][2]);*/

/*			glVertex3dv(str->vrtx[k]);
			

		}

	}
glEnd();*/ 

	/*TEXTURE SPHERE*/
	glBegin(GL_QUADS);

	for(i=0;i<N-stepn;i+=stepn){
		for(j=0;j<P-stepp;j+=stepp){

			k = i*P+j;
			glNormal3dv(str->norm[k]);
			glVertex3dv(str->vrtx[k]);

			k = i*P + (j+stepp);
			glNormal3dv(str->norm[k]);
			glVertex3dv(str->vrtx[k]);

			k = (i+stepn)*P+(j+stepp);
			glNormal3dv(str->norm[k]);
			glVertex3dv(str->vrtx[k]);

			k = (i+stepn)*P + j; 
			glNormal3dv(str->norm[k]);
			glVertex3dv(str->vrtx[k]);

		}
		/*k = i*P+j;
		glNormal3dv(str->norm[k]);
		glVertex3dv(str->vrtx[k]);

		k = i*P + (j+stepp);
		glNormal3dv(str->norm[k]);
		glVertex3dv(str->vrtx[k]);

		k = (i+stepn)*P+(j+stepp);
		glNormal3dv(str->norm[k]);
		glVertex3dv(str->vrtx[k]);

		k = (i+stepn)*P + j; 
		glNormal3dv(str->norm[k]);
		glVertex3dv(str->vrtx[k]);*/


	}

/*
glBegin(GL_POLYGON);

	for(j=0;j<P;j+=stepp){


		i=N-stepn;
		k = i+j;
		glNormal3dv(str->norm[k]);
		glVertex3dv(str->vrtx[k]);

		k = i + (j+stepp);
		glNormal3dv(str->norm[k]);
		glVertex3dv(str->vrtx[k]);

		i=0;
		k = (i+stepn)+(j+stepp);
		glNormal3dv(str->norm[k]);
		glVertex3dv(str->vrtx[k]);

		k = (i+stepn) + j; 
		glNormal3dv(str->norm[k]);
		glVertex3dv(str->vrtx[k]);

	}
*/

	/*glEnd();
	glBegin(GL_POLYGON);
*/
/*On raccommode */

	for(j=0;j<P-stepp;j+=stepp){
	/*	glVertex3dv(str->vrtx[N*P+j]);
		glVertex3dv(str->vrtx[N*P+j+stepp]);
		glVertex3dv(str->vrtx[(stepn)*N+j+stepp]);
		glVertex3dv(str->vrtx[(stepn)*N+j]);
*/
		i=0;
		k = i*P+j;
		glNormal3dv(str->norm[k]);
		glVertex3dv(str->vrtx[k]);
		

		k = i*P+j+stepp;
		glNormal3dv(str->norm[k]);
		glVertex3dv(str->vrtx[k]);
		

		i=N-stepn;


		k = i*P+j+stepp;
		glNormal3dv(str->norm[k]);
		glVertex3dv(str->vrtx[k]);

		k = i*P+j;
		glNormal3dv(str->norm[k]);
		glVertex3dv(str->vrtx[k]);
		
		


	}
	glEnd();

	/*On bouche le trou */

	glBegin(GL_POLYGON);
	j=P-stepp;
	for(i=0;i<N-stepn;i+=stepn){
		k = i*P+j;
		glNormal3dv(str->norm[k]);
		glVertex3dv(str->vrtx[k]);
	}

	glDisable(GL_LIGHTING);
	
	
	glEnd();
}

