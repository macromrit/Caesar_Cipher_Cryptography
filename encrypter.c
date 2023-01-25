#include <stdio.h>
#include <string.h>

int main(){
    char sample_space[] = "nJxSuQvbdrpmgtyFkXoL9VTAK75 0h3zC2WsR1EUN8lifcjMDHBwYGO64qeZIaP";
    char sample_input[501];
    char processed_content[501];
    int key;
    FILE *fi, *fo;

    fi = fopen("encrypt_input.txt", "r");
    fo = fopen("encrypt_output.txt", "w");
    fgets(sample_input,500, fi);

    sample_input[strlen(sample_input)] ='\0';

    printf("Input Key-> ");
    scanf("%i", &key);


    int j=0;
    int i=0;
    for(i=0; i<strlen(sample_input); i++){    
    
        for(j=0; j<strlen(sample_space)-1; j++){if(sample_input[i]==sample_space[j]){break;}}
        
        processed_content[i] = sample_space[(j+key)%strlen(sample_space)];
    }

    processed_content[strlen(processed_content)] = '\0';

    fputs(processed_content, fo);

    fclose(fi);fclose(fo);
    
    return 0;
}