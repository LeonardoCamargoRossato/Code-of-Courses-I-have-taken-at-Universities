Lista* cria_lista(void){
  Lista* l = (Lista*)malloc(sizeof(Lista));
  l->prim = NULL;
  return l;
}

void insere_lista(Lista* l, int info){
  ListaNo* novo = (ListaNo*)malloc(sizeof(ListaNo));
  novo->info = info;
  novo->prox = l->prim;
  l->prim = novo;
}

void imprime_lista(Lista* l){
  ListaNo* p;
  for(ListaNo* p=l->prim; p!=NULL; p=p->prox){
    printf("info = %d\n", p->info);
  }
}

int comprimento(Lista* l){
  ListaNo* p; int cont = 0;
  for(ListaNo* p=l->prim; p!=NULL; p=p->prox){
    cont++;
  }
  return cont;
}

int maiores(Lista* l,int x){
  ListaNo* p; int cont = 0;
  for(ListaNo* p=l->prim; p!=NULL; p=p->prox){
    if(p->info > x)
      cont++;
  }
  return cont;
}


int ultimo(Lista*l){
  ListaNo* p; int cont = 0;
  for(ListaNo* p=l->prim; p!=NULL; p=p->prox){
      cont++;
  }
  int cont2 = 0;
  for(ListaNo* p=l->prim; p!=NULL; p=p->prox){
    cont2++;
    if(cont2 == cont)
      return p->info;
  }
}

void libera_lista(Lista* l){
  ListaNo* p = l->prim;
  while(p != NULL){
    ListaNo* t = p->prox;
    free(p);
    p = t;
  }
  free(l);
}

Lista* concatena(Lista* l1,Lista* l2){
  ListaNo* p;
  for(ListaNo* p=l2->prim; p!=NULL; p=p->prox){
    insere_lista(l1,p->info);
  }
  libera_lista(l2);
  return l1;
}

void retira_n(Lista* l,int x){
  ListaNo* p = l->prim;
  ListaNo* ant = NULL;
  while(p != NULL && p->info != x){
    ant = p;
    p = p->prox;
  }
  if(p != NULL){ //verifica se achou o valor x na lista
    if(ant == NULL) //retira elem se x == ao primeiro elem da lista
      l->prim = p->prox;
    else //retira elem para (todos) os outros casos
      ant->prox = p->prox;
    free(p);
  }
}

static ListaNo* retira_nos(ListaNo* p,int x){
  puts("AAAAAA");
  if(p!=NULL){
    if(p->info == x){
      ListaNo* t = p;
      p=p->prox;
      free(t);
    }
    else
      p->prox = retira_nos(p->prox,x);
  }
  return p;
}

Lista* separa(Lista* l1,int x){
  ListaNo* p = l1->prim;
  int cont1 = 0; int cont_total = 0;
  while(p!=NULL && p->info!=x){
    cont1++; p = p->prox;
  }
  Lista* l2 = (Lista*)malloc(sizeof(Lista));
  Lista* l1_aux = (Lista*)malloc(sizeof(Lista));
  int cont2 = 0;
  for(ListaNo* p=l1->prim; p!=NULL; p=p->prox){
    cont2++;
    if(cont2 > cont1+1){
      insere_lista(l2,p->info);
    }
    else
      insere_lista(l1_aux,p->info);
  }
  free(l1);
  for(ListaNo* p=l1_aux->prim; p!=NULL; p=p->prox){
    cont2++;
    l1->prim = l1_aux->prim;
  }
  return l2;
}

//FUNÇÃO CALLBACK MERGE
int compara(Lista* l1,Lista*l2){
  ListaNo* p1 = l1->prim;
  ListaNo* p2 = l2->prim;
  int cont1 = 0; int cont2 = 0;
  while(p1!=NULL){
    cont1++; p1=p1->prox;
  }
  while(p2!=NULL){
    cont2++; p2=p2->prox;
  }
  if(cont1 >=cont2)
    return 1;
  else
    return -1;
}
Lista* merge(Lista* l1,Lista* l2){
  Lista* l3_aux = (Lista*)malloc(sizeof(Lista));
  Lista* l3 = (Lista*)malloc(sizeof(Lista));
  ListaNo* p1 = l1->prim;
  ListaNo* p2 = l2->prim;
  int cont = 0;
  while(p1!=NULL && p2!=NULL){
    insere_lista(l3_aux,p1->info);
    p1=p1->prox;
    insere_lista(l3_aux,p2->info);
    p2=p2->prox;
    cont++;
  }
  int p = compara(l1,l2);
  int cont2 = 0;
  if(p==1){
    while(p1!=NULL){
      cont2++;
      if(cont2 > cont){
        insere_lista(l3_aux,p1->info);
        p1=p1->prox;
      }
    }
  }
  else if(p==-1){
    while(p2!=NULL){
      cont2++;
      if(cont2 > cont){
        insere_lista(l3_aux,p2->info);
        p2=p2->prox;
      }
    }
  }
  ListaNo* p3 = l3_aux->prim;
  while(p3!=NULL){
    insere_lista(l3,p3->info);
    p3 = p3->prox;
  }
  libera_lista(l1); libera_lista(l2);
  return l3;
}

Lista* inverte(Lista* l1){
  ListaNo* p = l1->prim;
  Lista* l1_aux = cria_lista();
  int cont = 0;
  while(p!=NULL){
    cont++;
    insere_lista(l1_aux,p->info);
    p=p->prox;
  }
  libera_lista(l1);
  return l1_aux;
}

Lista* copia(Lista* l1){
  ListaNo* p = l1->prim;

  Lista* l1_aux = cria_lista();
  while(p!=NULL){
    insere_lista(l1_aux,p->info);
    p=p->prox;
  }
  Lista* l2_aux = cria_lista();
  ListaNo* p2 = l1_aux->prim;
  l1->prim = p2;
  while(p2!=NULL){
    insere_lista(l2_aux,p2->info);
    p2=p2->prox;
  }
  libera_lista(l1_aux);
  return l2_aux;
}

/////////////////////////////////////////////////////////////////////////
/// PARTE DAS FUNÇÕES QUE TRANSFORMA LISTA SIMPLES EM LISTA CIRCULAR  ///
/////////////////////////////////////////////////////////////////////////

void para_circular(Lista* l1){
  ListaNo* p; int cont = 0;
  for(ListaNo* p=l1->prim; p!=NULL; p=p->prox){
      cont++;
  }
  int cont2 = 0;
  for(ListaNo* p=l1->prim; p!=NULL; p=p->prox){
    cont2++;
    if(cont2 == cont){
      p->prox = l1->prim; break;
    }
  }
}

void imprime_circular(Lista* l1){
  ListaNo* p = l1->prim;
  printf("{ ");
  if(p!=NULL) do {
    printf("%d ",p->info);
    p=p->prox;
  } while(p!=l1->prim);
  printf("} \n");
}

/////////////////////////////////////////////////////////////////////
///            FUNÇÕES QUE ENVOLVEM LISTAS DUPLAS                 ///
/////////////////////////////////////////////////////////////////////

typedef struct listadupla ListaDupla;
typedef struct listanoduplo ListaNoDuplo;

struct listadupla{
  ListaNoDuplo* prim;
  ListaNoDuplo* ult;
};

struct listanoduplo{
  int info;
  ListaNoDuplo* ant;
  ListaNoDuplo* prox;
};

ListaDupla* cria_listadupla(void){
  ListaDupla* l = (ListaDupla*)malloc(sizeof(ListaDupla));
  l->prim = NULL;
  l->ult = NULL;
  return l;
}

void insere_inicio(ListaDupla* l, int info){
  ListaNoDuplo* novo = (ListaNoDuplo*)malloc(sizeof(ListaNoDuplo));
  novo->info = info;
  novo->prox = l->prim;
  novo->ant = NULL;

  if(l->prim != NULL){
    l->prim->ant = novo;
  }
  else
    l->ult = novo;
  l->prim = novo;
}

void insere_final(ListaDupla* l, int info){
  ListaNoDuplo* novo = (ListaNoDuplo*)malloc(sizeof(ListaNoDuplo));
  novo->info = info;
  novo->ant = l->ult;
  novo->prox = NULL;

  if(l->ult != NULL){
    l->ult->prox = novo;
  }
  else
    l->prim = novo;
  l->ult = novo;
}

void imprime_listadupla(ListaDupla* l){
  ListaNoDuplo* p;
  printf("{ ");
  for(ListaNoDuplo* p=l->prim; p!=l->ult; p=p->prox){
    printf("%d ", p->info);
  }
  printf("}\n");
}

void retira_inicio(ListaDupla* l){
  ListaNoDuplo* p = l->prim;
  if(p == NULL){
    return;
  }
  else
    l->prim = p->prox;
  free(p);
}
void retira_final(ListaDupla* l){
  ListaNoDuplo* p = l->ult;
  l->ult = p->ant;
  free(p);
}

void para_circulardupla(ListaDupla* l1){
  ListaNoDuplo* p; int cont1 = 0;
  for(ListaNoDuplo* p=l1->prim; p!=NULL; p=p->prox){
      cont1++;
  }
  int cont2 = 0;
  for(ListaNoDuplo* p=l1->prim; p!=NULL; p=p->prox){
    cont2++;
    if(cont2 == cont1){
      p->prox = l1->prim; break;
    }
  }

  ListaNoDuplo* p1; int cont3 = 0;
  for(ListaNoDuplo* p1=l1->ult; p1!=NULL; p1=p1->ant){
      cont3++;
  }
  int cont4 = 0;
  for(ListaNoDuplo* p1=l1->ult; p1!=NULL; p1=p1->ant){
    cont4++;
    if(cont4 == cont3){
     p1->ant = l1->ult; break;
    }
  }
}
