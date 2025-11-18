//https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
int insert(char s,int i , int **posi){
    if((*posi)[s] != -1){
        //printf("1 -- %c\n", s);
        return 0;
    }
    (*posi)[s] = i;
    return 1;
}
int lengthOfLongestSubstring(char* s) {
    int *posi = malloc(300*sizeof(int)), tam = 0, i = 0;
    for(int j = 0; j < 300; j++){
        posi[j] = -1;
    }
    int resp = 0;
    while(s[i] != '\0'){
       // printf("%d~ ",resp);
        if(insert(s[i],i, &posi)){
            //printf("1 -- %c\n", s[i]);
           //printf("(%d)\n", tam);
            tam++;
            i++;
        }else{
            //printf("2 -- %c\n", s[i]);
            int *posi2 = malloc(300*sizeof(int));
            for(int j = 0; j < 300; j++){
                posi2[j] = -1;
            }
            for(int j = posi[s[i]]+1; j <= i; j++){
                insert(s[j], j, &posi2);
            }
            int aux = i - posi[s[i]];
            printf("(-i = %d  s[i] = %c-    posi[s[i]] = %d)\n", i, s[i], posi[s[i]]);
            i++;
            while(s[i] != '\0' && insert(s[i],i, &posi2)){
                printf("%c", s[i]);
                i++;
                aux++;
            }
            
            if(aux >= tam){
                //printf("troca\n");
                tam = aux;
                free(posi);
                posi = posi2;
            }
            posi2 = NULL;
            free(posi2);
            if(tam > resp)
                resp = tam;
            tam = 0;
        }
    }
    if(resp == 0)
        return tam;
    return resp;
}
