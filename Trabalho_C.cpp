#include <stdio.h>

int senha;
float saldo;
int resp; //armazena a resposta
float maiorDeposito = 0;

bool CriarSenha()
{
	

	do{
		printf("Digite uma senha de 4 digitos: ");
		scanf("%d", &senha);
		
		if(senha > 9999 || senha < 0)
		{
			printf("Senha invalida, digite outra senha\n");
		}
		
	} while (senha > 9999 || senha < 0);
	
	printf("Senha criada com sucesso :)");
	
	
	return true;
}

float Depositar()
{
	float valor;
	
	do
	{
		printf("Qual valor voce gostaria de depositar? \n: ");
		scanf("%f", &valor);
		
		if(valor <= 0)
		{
			printf("Valor invalido, digite um valor maior que zero!\n");
		}
		
	}while (valor <= 0);
	
	if(valor > maiorDeposito)
	{
		maiorDeposito = valor;
	}
	
	
	saldo += valor;
	printf("saldo resultante: %2.f\n", saldo);
	
	return saldo;
}

float Sacar()
{
	float valor;
	int respSenha;
	
	printf("Digite sua senha \n:");
	scanf("%d", &respSenha);
	if(senha != respSenha)
	{
		printf("Senha incorreta, operação cancelada!");
		return 0;
	}
	
	do
	{
		printf("Voce tem %2.f RS \nQuanto voce gostaria de sacar?\n: ", saldo);
		scanf("%f", &valor);
		
		if(valor <= 0)
		{
			printf("Voce nao pode sacar esse dinheiro, Saldo insuficiente!\n");
		}
	} while(valor > saldo);
	
	
	saldo -= valor;
	
	printf("saldo resultante: %2.f\n", saldo);

	
	return saldo;
}

void Estatisticas()
{
	printf("Saldo: %2.f RS\nMaior Deposito: %2.f RS\n\n", saldo, maiorDeposito);
	
}

int main()
{
	if(CriarSenha() == true)
	{
		saldo = 500;
	}

	while(true)
	{
		printf("O que voce gostaria de fazer? \n 1- Depositar\n 2- Sacar\n 3- Consultar saldo e estatisticas\n 4- sair\n : ");
		scanf("%d", &resp);
		
		if(resp == 1)
		{
			Depositar();
		}
		else if(resp == 2)
		{
			Sacar();
		}
		else if(resp == 3)
		{
			Estatisticas();
		}
		else if(resp == 4)
		{
			printf("Obrigado por usar nosso banco!!");
			break;
		}
			
	}
	
	return 0;
}


