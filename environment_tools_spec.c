#include <stdio.h>
#include "minishell.h"

int	main(int ac, char **av, char **envp)
{
	environment = (char**)ft_tabdup((const void**)envp, (void*)&strdup);

	/*
	printf("tests for keycmp:\n");
	printf("expected 1 got %d\n", keycmp("VAR", "VAX"));
	printf("expected 0 got %d\n", keycmp("VAR", "VAR"));
	printf("expected 0 got %d\n", keycmp("VAR=", "VAR="));
	printf("expected 0 got %d\n", keycmp("VAR=content", "VAR"));
	printf("expected 0 got %d\n", keycmp("VAR", "VAR=content"));
	printf("expected 0 got %d\n", keycmp("VAR=content", "VAR=content"));
	printf("expected 0 got %d\n", keycmp("VAR=content1", "VAR=content2"));
	printf("expected 1 got %d\n", keycmp("VAR", "RAV"));
	printf("expected 1 got %d\n", keycmp("VAR=", "RAV="));
	printf("expected 1 got %d\n", keycmp("VAR=content", "RAV"));
	printf("expected 1 got %d\n", keycmp("VAR", "RAV=content"));
	printf("expected 1 got %d\n", keycmp("VAR=content", "RAV=content"));
	*/
	printf("tests for get_key_value:\n");
	environment = (char**)ft_tabpush((void**)environment, "VAR=content", 0, (void*)&ft_strdup);
	environment = (char**)ft_tabpush((void**)environment, "RAV========", 0, (void*)&ft_strdup);
	environment = (char**)ft_tabpush((void**)environment, "NONE", 0, (void*)&ft_strdup);
	printf("expected 'content' got '%s'\n", get_key_value(environment, "VAR"));
	printf("expected 'content' got '%s'\n", get_key_value(environment, "VAR=content"));
	printf("expected 'content' got '%s'\n", get_key_value(environment, "VAR=nottherightcontent"));
	printf("expected '=======' got '%s'\n", get_key_value(environment, "RAV"));
	printf("expected null got '%s'\n", get_key_value(environment, "NONE"));
	/*
	printf("tests for valid_envar_name:\n");
	printf("expected 1 got %d\n", valid_envar_name("VAR"));
	printf("expected 1 got %d\n", valid_envar_name("var"));
	printf("expected 1 got %d\n", valid_envar_name("VAr"));
	printf("expected 0 got %d\n", valid_envar_name("VAR="));
	printf("expected 0 got %d\n", valid_envar_name("VAR,"));
	printf("expected 0 got %d\n", valid_envar_name("_,"));
	printf("expected 0 got %d\n", valid_envar_name(",_"));
	printf("expected 0 got %d\n", valid_envar_name("255_VAR"));
	printf("expected 1 got %d\n", valid_envar_name("_255_VAR"));
	printf("expected 1 got %d\n", valid_envar_name("V255"));
	printf("expected 0 got %d\n", valid_envar_name("\"VAR\'"));
	*/

//	printf("tests for push_envar:\n");

	ft_tabfree((void**)environment);

	return (0);
}
