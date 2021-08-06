void minuscula(char* str){
    int j;
    for(j=0; str[j]; j++){
            str[j] = tolower(str[j]);
    }
}

// node *file_to_vector(FILE *dicionario){
//     char str[46];
//     int i = 0;
//     node* palavras = malloc(sizeof(node)*6);

//     while (fgets(str, sizeof(str), dicionario) != NULL)
//     {       
//         str[strlen(str)-1]=0;
//         Minuscula(str);
//         strcpy(palavras[i].palavra, str);
//         bubble_sort(str);
//         strcpy(palavras[i].palavra_ord, str);
//         i++;
//     }
//     return palavras;
// }