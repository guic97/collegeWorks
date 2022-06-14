#include<stdio.h>
#define QTD 9999
#define MAX 6

void dijkstra (int G[MAX][MAX], int n, int inicial);

int main(){
  int i, j, u, l, p;
  int G[MAX][MAX];

  for(l=1 ; l<MAX; l++){
    for(p=1; p<MAX; p++){
      G[l][p] =-1;
    }
  }

  	G[1][2] =200;
	G[1][3] =0;
	G[2][4] =0;
	G[2][5] =200;
	G[3][2] =400;
	G[3][5] =300;
	G[4][5] =500;

  for(l=1 ; l<MAX; l++){
    for( p=1; p<MAX; p++){
      printf("%d,", G[l][p]);
    }
    printf("\n");
  }

  printf("\nInforme o node inicial:");
  scanf("%d",&u);
  dijkstra(G, MAX, u);

  return 0;
}

void dijkstra(int G[MAX][MAX], int n, int inicial)
{
  int custo[n][n], distancia[n], pred[n];
  int visitado[n], cont, distanciamin, proxno, i, j;

  for(i=1; i<n; i++)
    for(j=1; j<n; j++)
      if(G[i][j]==-1)
        custo[i][j] = QTD;
      else
        custo[i][j] = G[i][j];

  for(i=1; i<n; i++){
    distancia[i] = custo[inicial][i];
    pred[i] = inicial;
    visitado[i]=0;
  }

  distancia[inicial]=0;
  visitado[inicial]=1;
  cont=1;

  while(cont<n-1){
    distanciamin=QTD;
    for(i=0; i<n; i++)
      if(distancia[i]<distanciamin&&!visitado[i]){
        distanciamin = distancia[i];
        proxno = i;
      }

    visitado[proxno]=1;
    for(i=0; i<n; i++){
      if(!visitado[i])
        if(distanciamin + custo[proxno][i] < distancia[i]){
          distancia[i] = distanciamin + custo[proxno][i];
          pred[i] = proxno;
        }
      }
      cont++;
    }

    for(i=1; i<n; i++)
      if(i!=inicial){
        printf("\n\nDistancia do no %d = %d",i,distancia[i]);
        printf("\nCaminho = %d",i);

        j=i;
        do{
          j=pred[j];
          printf("<-%d",j);
        }while(j != inicial);
      }
      printf(" <- menor caminho.");
}
