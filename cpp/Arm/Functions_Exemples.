/*
  ==============================================
  Code developed by Nícolas Auersvalt
  Project Robotic Arm with Claw
  Current Version (1.0)
  ==============================================
*/
/*

  Será necessário testar os ângulos limites da garra
  e depois substituir os valores em claw_min_lim e 
  claw_max_lim.

  Pensar em um modo de otimizar a função da garra
  pois o código lerá toda vez a mesma função.

  É necessário atualizar o pino que o motor da
  garra está conectada.

  Verificar se por estar conectado a um pino
  analógico, a garra vai imprimir valores digitais
  ou analógicos e converter esse valor utilizando
  uma função map diretamente no valor mínimo limite
  e máximo limite.

*/

/*
// Funções

==============================================
// Braço Robótico
==============================================

Inicialmente, precisamos definir valores limites do ângulo
de giro para evitar danos físicos. 

Além disso, definimos os motores com suas seguintes funções:

Motor Esquerdo - Responsável pela Altura que o braço atinge;
Motor Direito - Responsável pela Profundidade que o braço 
estica ou retrai.

Assim, podemos atribuir os limites de acordo com a definição:

Limites Máximos:

Esquerda = 73;
Direita = 120;
Base = 180;
Garra = ?.

Limites Mínimos:

Esquerda = Direita = 20;
Base = 1;
Garras = ?.

Para o movimento de expansão e retração do braço, são utilizados
os motores de altura e profundidade de tal forma que o valor
atribuído a um deve ser diferente do outro, pois estão em 
posições e sentidos diferentes:

O método encontrado foi encontrar um valor, atribuir a um motor
e subtrair por 180 para atribuir ao outro motor.

Dado x, se {alfa, beta pertence aos reais tal que 
alfa = 180 - x e beta = x}, então x e y serão simétricos em 
relação ao eixo y do primeiro e segundo quadrante se, e 
somente se, x < 90°.

Para incorporar este projeto ao WitBot, será necessário atualizar
o valor de leitura do joystick para o joystick virtual, sendo
recomendado criar uma função específica para isso.
Além disso, vale ressaltar a necessidade de aumentar o delay
quando conectado ao Blynk e prestar atenção na alimentação
exigida pelos componentes atuais.

*/

