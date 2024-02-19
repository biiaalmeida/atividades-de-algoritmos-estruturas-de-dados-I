//2. Dado a função abaixo, qual a complexidade de tempo
int funcao_aula(int max1, int max2){
    int count1, count2; //1 vez: c1
    for(count1=0; count1<max1; count1++){ //c2: n vezes
        for(count2=0; count2<max2; count2++){ //c3: n * n vezes
            printf("Exemplo da aula"); //c4: n² vezes
        }
    }
    return 0; //c5: uma vez
}

/*T(funcao_aula) = c1 + nc2 + n²c3 + n²c4 + c5
 T(funcao_aula)= (c3+c4)n² + nc2 + (c1+c5) :. a = (c3+c4) | b = (c1+c5) | c = c2
 T(funcao_aula) = an² + bn + c

 SIMPLIFICAÇÃO DA EXPRESSÃO DO TEMPO: 
 T(funcao_aula) = an² + bn
 T(funcao_aula) = an²
 T(funcao_aula) = n²

 Notação Big-O
 T(funcao_aula) = O(n²)
*/
