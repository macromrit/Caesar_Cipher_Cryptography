#include <stdio.h>
#include <string.h>


int main(){
    //set of characters to choose from shuffle and encrypt the data
    char sample_space[] = "nJxSuQvbdrpmgtyFkXoL9VTAK75 0h3zC2WsR1EUN8lifcjMDHBwYGO64qeZIaP";

    //content fed in by the user
    char content_feed[501];
    
    //final content or decrypted output
    char processed_content[501];
    
    //number of reverse jumps a.k.a apha swaps to be made for the model fed in
    int key;
    
    //opening file for reading and writting
    FILE *fi, *fo;
    
    fi = fopen("decrypt_input.txt", "r");
    fo = fopen("decrypt_output.txt", "w");

    fgets(content_feed, 500, fi);
    printf("Input Key-> ");
    scanf("%i", &key);


    //forloop 1 traverse thru the content fed in, simulatneously decrypts the data index by index as well
    for(int i=0; i<strlen(content_feed); i++){

        //tho its a nasty idea, implementing forloop2 for locating content_feed[i]'s index in sample_space
        int j=0;
        
        // an extra holder to make readable code
        char element_2_resolve = content_feed[i];
        
        //traversing thru sample_space for locating the element || check aight
        for(j=0; j<strlen(sample_space); ++j){
            if(element_2_resolve==sample_space[j]){
                break;
            }
        }

        //reversation -> subracting j by key
        //located index as per the formula j-key can be discovered for implementation
        //gcc ain't have the audacity to process negative indexing
        //hence, dividing this segment into 2 branches 
        //the first's for positive indexing and the next's takes care of negative indexing
        //if the number's positive
        if(j-key>=0){
            processed_content[i] = sample_space[j-key];    
        }

        //else it's negative
        //formula for negative indexing -> len(sample_space)-[located index] ->strlen(sample_space)-(j-key)
        else{
            processed_content[i] = sample_space[strlen(sample_space)+(j-key)];
        }

   }

    processed_content[strlen(processed_content)] = '\0';

    fputs(processed_content, fo);
    
    fclose(fi);fclose(fo);

    return 0;
}