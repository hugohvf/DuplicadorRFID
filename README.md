# Duplicador RFID

## Circuito

![Schematics](/images/schematics.png)


## Materiais

- Arduino nano
- Leitor RFID RC522
- 2 leds e 2 resistores 220 ohms

## Uso

Após a montagem basta upar o código para o arduino e ligar.

Ele ficara com a luz azul acesa quando estiver pronto para ler. Colocando uma tag de 13,56 Mhz na frente ele irá ler suas informações e guardar. Após a leitura o led vermelho acenderá indicando que já  é possível colocar outra tag (tem que ter o uid regravável) para escrever nela e copiar as informações. Finalizando a gravaçào ele volta para luz azul para ler outra tag

O processo foi feito usando o arduino nano, para usar outro precisara ver quais portas o modulo rfid usa para conectar e alterar o código para usar as portas leds corretas

## Exemplo de montagem

![Top](/images/top.jpg)

![Side](/images/side.jpg)