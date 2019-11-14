#include <SPI.h> 
#include <SD.h> 
const int chipSelect = 10; //PINO DIGITAL UTILIZADO PELO TERMINAL CS DO MÓDULO

void setup(){
  Serial.begin(9600); 
   while(!Serial){
  }
  Serial.println("Inicializando o cartão de memória..."); 
  Serial.println("********************************************"); 
  pinMode(SS, OUTPUT); 
  
  if(!SD.begin(chipSelect)){ //SE O CARTÃO DE MEMÓRIA NÃO ESTIVER PRESENTE OU FALHAR
    Serial.println("Cartão de memória falhou ou não está presente!"); 
    return; 
  }
  Serial.println("Cartão de memória inicializado com sucesso!"); 
  Serial.println("********************************************"); 
  Serial.println("Mensagem do arquivo de texto que está no cartão de memória:"); 
  Serial.println(); 
   
  SDFile dataFile = SD.open("arquivo.txt"); //dataFile RECEBE O CONTEÚDO DO ARQUIVO DE TEXTO (ABRIR UM ARQUIVO POR VEZ)

  if(dataFile){ 
    while(dataFile.available()){ 
      Serial.write(dataFile.read()); 
    }
    dataFile.close();
  }
  else{ //SENÃO, FAZ
    Serial.println("Erro ao abrir o arquivo!"); 
  } 
}
void loop(){
}
