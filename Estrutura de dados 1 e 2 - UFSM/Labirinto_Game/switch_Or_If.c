char x;
volta: printf(" 'w': p/Cima. \t 'd': p/Direita. \t 'a': p/Esquerda.  \t 's': p/Baixo \t 'e': p/sair do programa. \n --> ");
switch (x) {
  case 'w':{ IrPraCima_main = IrPraCima(cria_main,i,j,n);
    i = IrPraCima_main; goto volta;}
  case 'd':{ IrPraDireita_main = IrPraDireita(cria_main,i,j,n);
    j = IrPraDireita_main; goto volta;}
  case 'a':{ IrPraEsquerda_main = IrPraEsquerda(cria_main,i,j,n);
    j = IrPraEsquerda_main; goto volta;}
  case 's':{ IrPraBaixo_main = IrPraBaixo(cria_main,i,j,n);
    i = IrPraBaixo_main; goto volta;}
  case 'e': break;
  default: break;
}

char x;
volta: printf(" 'w': Ir pra Cima. \n 'd': Ir pra Direita. \n 'a': Ir pra Esquerda.  \n 's': Ir pra Baixo \n 'e':  p/sair do programa. \n --> ");
scanf(" %c", &x);
if (x == 'w'){ IrPraCima_main = IrPraCima(cria_main,i,j,n);
  i = IrPraBaixo_main; goto volta;}
else if(x == 'd'){ IrPraDireita_main = IrPraDireita(cria_main,i,j,n);
  j = IrPraDireita_main; goto volta;}
else if(x == 'a'){ IrPraEsquerda_main = IrPraEsquerda(cria_main,i,j,n);
  j = IrPraEsquerda_main; goto volta;}
else if(x == 's'){ IrPraBaixo_main = IrPraBaixo(cria_main,i,j,n);
  i = IrPraBaixo_main; goto volta;}
else if(x == 'e') {exit(0);}




else if (cria_main[i][j] == NULL){
  printf("Memoria Insuficiente."); exit(1);
}

else if (x == 'w'){ IrPraCima_main = IrPraCima(cria_main,i,j,n,cont_pontos);
  i = IrPraCima_main; goto volta;}
else if(x == 'd'){ IrPraDireita_main = IrPraDireita(cria_main,i,j,n,cont_pontos);
  j = IrPraDireita_main; goto volta;}
else if(x == 'a'){ IrPraEsquerda_main = IrPraEsquerda(cria_main,i,j,n,cont_pontos);
  j = IrPraEsquerda_main; goto volta;}
else if(x == 's'){ IrPraBaixo_main = IrPraBaixo(cria_main,i,j,n,cont_pontos);
  i = IrPraBaixo_main; goto volta;}
else if(x == 'e') {func_free(cria_main,n); exit(0);}
