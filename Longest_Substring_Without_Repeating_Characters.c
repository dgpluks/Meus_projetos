//https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
int insert(char s,int i , int **posi){
    if((*posi)[s] == -1){
        (*posi)[s] = i;
        return 1;
    }else{
        return 0;
    }
}
int lengthOfLongestSubstring(char* s) {
    int *posi = malloc(300*sizeof(int)), tam = 0, i = 0;
    for(int j = 0; j < 300; j++){
        posi[j] = -1;
    }
    while(s[i] != '\0'){
        if(insert(s[i],i, &posi)){
            tam++;
            i++;
        }else{
            int *posi2 = malloc(300*sizeof(int));
            for(int j = 0; j < 300; j++){
                posi2[j] = -1;
            }
            for(int j = posi[s[i]]+1; j <= i; j++){
                insert(s[j], j, &posi2);
            }
            int aux = i - posi[s[i]];
            i++;
            while(s[i] != '\0' && insert(s[i],i, &posi)){
                i++;
                aux++;
            }
            if(aux > tam){
                tam = aux;
                free(posi);
                posi = posi2;
                posi2 = NULL;
                free(posi2);
            }
        }
    }
    return tam;
}
