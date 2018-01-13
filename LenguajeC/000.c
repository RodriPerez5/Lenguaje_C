//
// #include <stdio.h>
// #include <stdlib.h>
//
//
// void RecorrerArbol( int **Matriz, int Ax, int Ay, int Bx, int By );
//
// int SoloNodoPadre=0;
//
// int main( ) {
//    int Ax, Ay, Bx, By;
//    printf(" Ingrese la posición inicial (Ax,Ay):\n   Ax= ");
//    scanf("%d", &Ax);
//    printf("   Ay= ");
//    scanf("%d", &Ay);
//    printf(" Ingrese la posición final (Bx,By):\n   Bx= ");
//    scanf("%d", &Bx);
//    printf("   By= ");
//    scanf("%d", &By);
//    // Ax=0;
//    // Ay=1;
//    // Bx=3;
//    // By=3;
//
//    // int Mapa[10][10]= { {1,0,0,0,0,1,1,1,1,1},
//    //                     {1,1,0,0,0,1,0,0,0,0},
//    //                     {0,1,0,0,0,1,0,0,0,0},
//    //                     {0,1,0,0,0,1,0,0,0,0},
//    //                     {0,1,0,0,0,1,0,0,0,0},
//    //                     {0,1,0,0,0,1,1,0,0,0},
//    //                     {0,1,0,0,0,0,1,1,1,1},
//    //                     {0,1,0,0,0,0,0,0,0,1},
//    //                     {0,1,0,0,0,0,0,0,0,1},
//    //                     {0,1,1,1,1,1,1,1,1,0}  };
//    // int Mapa[10][10]= { {0,0,0,0,0,1,0,0,0,0},
//    //                     {0,0,0,0,0,1,0,0,0,0},
//    //                     {0,0,0,0,0,1,0,0,0,0},
//    //                     {0,0,0,0,0,1,0,0,0,0},
//    //                     {0,0,0,0,0,1,0,0,0,0},
//    //                     {0,0,0,0,0,1,0,0,0,0},
//    //                     {0,0,0,0,0,1,0,0,0,0},
//    //                     {0,0,0,0,0,1,0,0,0,0},
//    //                     {0,0,0,0,0,0,0,0,0,0},
//    //                     {0,0,0,0,0,1,0,0,0,0}  };
//    int Mapa[10][10]= { {0,0,0,0,0,0,0,0,0,0},
//                        {0,0,0,0,0,0,0,0,0,0},
//                        {0,0,0,0,0,0,0,0,0,0},
//                        {0,0,0,0,0,0,0,0,0,0},
//                        {0,0,0,0,0,0,0,0,0,0},
//                        {1,1,0,1,1,1,1,1,1,1},
//                        {0,0,0,0,0,0,0,0,0,0},
//                        {0,0,0,0,0,0,0,0,0,0},
//                        {0,0,0,0,0,0,0,0,0,0},
//                        {0,0,0,0,0,0,0,0,0,0}  };
//
//    int **Matriz;
//    Matriz = malloc( 10*sizeof(int *) );
//    for ( int i=0; i<10; i++) {
//      Matriz[i] = malloc( 10*sizeof(int) );
//    }
//
//    // **Matriz = **Mapa;// Se puede no usar los for para que el apuntador doble Matriz apunte a Mapa?
//    for ( int i=0; i<10; i++) {
//      for ( int j=0; j<10; j++) {
//        Matriz[i][j]=Mapa[i][j];
//      }
//    }
//
//    // printf("\n");
//    // for ( int i=0; i<10; i++) {
//    //   printf("         ");
//    //   for ( int j=0; j<10; j++) {
//    //     printf(" %d\t", Matriz[i][j]);
//    //   }
//    //   printf("\n");
//    // }
//
//
//    if ( Matriz[Ax][Ay]!=0   ||   (Ax<0  ||  9<Ay) ) {
//      printf(" Introduzca una posición inicial válida");
//    }else if( Matriz[Bx][By]!=0   ||   (Bx<0  ||  9<By) ) {
//      printf(" Introduzca una posición inicial válida");
//    }else {
//      RecorrerArbol( Matriz, Ax, Ay, Bx, By);
//      printf("\n######## No Existe Un Camino Entre A y B ########\n");
//      for ( int i=0; i<10; i++) {
//        printf("         ");
//        for ( int j=0; j<10; j++) {
//          printf(" %d\t", Matriz[i][j]);
//        }
//        printf("\n");
//      }
//      printf("\n");
//    }
//
//
//    return 0;
// }
//
//
//
//
//
//
//
// void RecorrerArbol( int **Matriz, int Ax, int Ay, int Bx, int By ) {
//    printf("\n           ______(%d,%d)______", Ax, Ay);
//
//    if ( SoloNodoPadre==0 ) {
//      Matriz[Ax][Ay] = 8;
//      SoloNodoPadre=777;//En todos los nodos hijos SoloNodoPadre será igual a 777
//    }else {
//      Matriz[Ax][Ay] = 5;
//    }
//
//    // printf("\n");
//    // for ( int i=0; i<10; i++) {
//    //   printf("         ");
//    //   for ( int j=0; j<10; j++) {
//    //     printf(" %d\t", Matriz[i][j]);
//    //   }
//    //   printf("\n");
//    // }
//    // printf("\n");
//
//    if ( Ax<Bx  &&  Ay<By ) {//////////////////////////////////////////////////////////////////////////////////////////////////
//      for ( int i=(Ax+1); i>=(Ax-1); i--) {
//        for ( int j=(Ay+1); j>=(Ay-1); j--) {
//          if (  (i!=Ax || j!=Ay)   &&   (0<=i && i<=9 && 0<=j && j<=9)  &&  (Matriz[i][j]==0)  ) {
//            if ( i!=Bx || j!=By ) {
//              RecorrerArbol( Matriz, i, j, Bx, By);
//            }else{
//              printf("\n           ______(%d,%d)______", i, j);
//              printf("\n######## ENCONTRADO! ########\n");
//
//              Matriz[i][j] = 9;
//
//              printf("\n");
//              for ( int i=0; i<10; i++) {
//                printf("         ");
//                for ( int j=0; j<10; j++) {
//                  printf(" %d\t", Matriz[i][j]);
//                }
//                printf("\n");
//              }
//              printf("\n");
//
//              abort();
//            }
//          }
//        }
//      }
//    }else if ( Ax>Bx  &&  Ay>By ) {//////////////////////////////////////////////////////////////////////////////////////////
//      for ( int i=(Ax-1); i<=(Ax+1); i++) {
//        for ( int j=(Ay-1); j<=(Ay+1); j++) {
//          if (  (i!=Ax || j!=Ay)   &&   (0<=i && i<=9 && 0<=j && j<=9)  &&  (Matriz[i][j]==0)  ) {
//            if ( i!=Bx || j!=By ) {
//              RecorrerArbol( Matriz, i, j, Bx, By);
//            }else{
//              printf("\n           ______(%d,%d)______", i, j);
//              printf("\n######## ENCONTRADO! ########\n");
//
//              Matriz[i][j] = 9;
//
//              printf("\n");
//              for ( int i=0; i<10; i++) {
//                printf("         ");
//                for ( int j=0; j<10; j++) {
//                  printf(" %d\t", Matriz[i][j]);
//                }
//                printf("\n");
//              }
//              printf("\n");
//
//              abort();
//            }
//          }
//        }
//      }
//    }else if ( Ax<Bx  &&  Ay>By ) {///////////////////////////////////////////////////////////////////////////////////////////
//      for ( int i=(Ax+1); i>=(Ax-1); i--) {
//        for ( int j=(Ay-1); j<=(Ay+1); j++) {
//          if (  (i!=Ax || j!=Ay)   &&   (0<=i && i<=9 && 0<=j && j<=9)  &&  (Matriz[i][j]==0)  ) {
//            if ( i!=Bx || j!=By ) {
//              RecorrerArbol( Matriz, i, j, Bx, By);
//            }else{
//              printf("\n           ______(%d,%d)______", i, j);
//              printf("\n######## ENCONTRADO! ########\n");
//
//              Matriz[i][j] = 9;
//
//              printf("\n");
//              for ( int i=0; i<10; i++) {
//                printf("         ");
//                for ( int j=0; j<10; j++) {
//                  printf(" %d\t", Matriz[i][j]);
//                }
//                printf("\n");
//              }
//              printf("\n");
//
//              abort();
//            }
//          }
//        }
//      }
//    }else if ( Ax>Bx  &&  Ay<By ) {///////////////////////////////////////////////////////////////////////////////////////////
//      for ( int i=(Ax-1); i<=(Ax+1); i++) {
//        for ( int j=(Ay+1); j>=(Ay-1); j--) {
//          if (  (i!=Ax || j!=Ay)   &&   (0<=i && i<=9 && 0<=j && j<=9)  &&  (Matriz[i][j]==0)  ) {
//            if ( i!=Bx || j!=By ) {
//              RecorrerArbol( Matriz, i, j, Bx, By);
//            }else{
//              printf("\n           ______(%d,%d)______", i, j);
//              printf("\n######## ENCONTRADO! ########\n");
//
//              Matriz[i][j] = 9;
//
//              printf("\n");
//              for ( int i=0; i<10; i++) {
//                printf("         ");
//                for ( int j=0; j<10; j++) {
//                  printf(" %d\t", Matriz[i][j]);
//                }
//                printf("\n");
//              }
//              printf("\n");
//
//              abort();
//            }
//          }
//        }
//      }
//    }else if ( Ax>Bx  &&  Ay==By ) {/////////////////////////////////////////////////////////////////////////////////////////
//      for ( int i=(Ax-1); i<=(Ax+1); i++) {
//        int uj, vj;
//        if ( Matriz[Ax-1][Ay]==0 ) {
//          uj=vj=Ay;
//        }else{
//          uj=(Ay-1);
//          vj=(Ay+1);
//        }
//        for ( int j=uj; j<=vj; j++) {
//          if (  (i!=Ax || j!=Ay)   &&   (0<=i && i<=9 && 0<=j && j<=9)  &&  (Matriz[i][j]==0)  ) {
//            if ( i!=Bx || j!=By ) {
//              RecorrerArbol( Matriz, i, j, Bx, By);
//            }else{
//              printf("\n           ______(%d,%d)______", i, j);
//              printf("\n######## ENCONTRADO! ########\n");
//
//              Matriz[i][j] = 9;
//
//              printf("\n");
//              for ( int i=0; i<10; i++) {
//                printf("         ");
//                for ( int j=0; j<10; j++) {
//                  printf(" %d\t", Matriz[i][j]);
//                }
//                printf("\n");
//              }
//              printf("\n");
//
//              abort();
//            }
//          }
//        }
//      }
//    }else if ( Ax<Bx  &&  Ay==By ) {///////////////////////////////////////////////////////////////////////////////////////////
//      for ( int i=(Ax+1); i>=(Ax-1); i--) {
//        int uj, vj;
//        if ( Matriz[Ax+1][Ay]==0 ) {
//          uj=vj=Ay;
//        }else{
//          uj=(Ay-1);
//          vj=(Ay+1);
//        }
//        for ( int j=uj; j<=vj; j++) {
//          if (  (i!=Ax || j!=Ay)   &&   (0<=i && i<=9 && 0<=j && j<=9)  &&  (Matriz[i][j]==0)  ) {
//            if ( i!=Bx || j!=By ) {
//              RecorrerArbol( Matriz, i, j, Bx, By);
//            }else{
//              printf("\n           ______(%d,%d)______", i, j);
//              printf("\n######## ENCONTRADO! ########\n");
//
//              Matriz[i][j] = 9;
//
//              printf("\n");
//              for ( int i=0; i<10; i++) {
//                printf("         ");
//                for ( int j=0; j<10; j++) {
//                  printf(" %d\t", Matriz[i][j]);
//                }
//                printf("\n");
//              }
//              printf("\n");
//
//              abort();
//            }
//          }
//        }
//      }
//    }else if ( Ax==Bx  &&  Ay>By ) {//////////////////////////////////////////////////////////////////////////////////////////
//      int ui, vi;
//      if ( Matriz[Ax][Ay-1]==0 ) {
//        ui=vi=Ax;
//      }else{
//        ui=(Ax-1);
//        vi=(Ax+1);
//      }
//      for ( int i=ui; i<=vi; i++) {
//        for ( int j=(Ay-1); j<=(Ay+1); j++) {
//          if (  (i!=Ax || j!=Ay)   &&   (0<=i && i<=9 && 0<=j && j<=9)  &&  (Matriz[i][j]==0)  ) {
//            if ( i!=Bx || j!=By ) {
//              RecorrerArbol( Matriz, i, j, Bx, By);
//            }else{
//              printf("\n           ______(%d,%d)______", i, j);
//              printf("\n######## ENCONTRADO! ########\n");
//
//              Matriz[i][j] = 9;
//
//              printf("\n");
//              for ( int i=0; i<10; i++) {
//                printf("         ");
//                for ( int j=0; j<10; j++) {
//                  printf(" %d\t", Matriz[i][j]);
//                }
//                printf("\n");
//              }
//              printf("\n");
//
//              abort();
//            }
//          }
//        }
//      }
//    }else if ( Ax==Bx  &&  Ay<By ) {///////////////////////////////////////////////////////////////////////////////////////////
//      int ui, vi;
//      if ( Matriz[Ax][Ay+1]==0 ) {
//        ui=vi=Ax;
//      }else{
//        ui=(Ax-1);
//        vi=(Ax+1);
//      }
//      for ( int i=ui; i<=vi; i++) {
//        for ( int j=(Ay+1); j>=(Ay-1); j--) {
//          if (  (i!=Ax || j!=Ay)   &&   (0<=i && i<=9 && 0<=j && j<=9)  &&  (Matriz[i][j]==0)  ) {
//            if ( i!=Bx || j!=By ) {
//              RecorrerArbol( Matriz, i, j, Bx, By);
//            }else{
//              printf("\n           ______(%d,%d)______", i, j);
//              printf("\n######## ENCONTRADO! ########\n");
//
//              Matriz[i][j] = 9;
//
//              printf("\n");
//              for ( int i=0; i<10; i++) {
//                printf("         ");
//                for ( int j=0; j<10; j++) {
//                  printf(" %d\t", Matriz[i][j]);
//                }
//                printf("\n");
//              }
//              printf("\n");
//
//              abort();
//            }
//          }
//        }
//      }
//    }
//
//
// }
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
// //
