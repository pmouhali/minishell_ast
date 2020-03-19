#include <stdio.h>
#include "minishell.h"

int	main(int ac, char **av, char **envp)
{
	environment = (char**)ft_tabdup((const void**)envp, (void*)&ft_strdup);

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

	printf("tests for get_key_value:\n");
	environment = (char**)ft_tabpush((void**)environment, "VAR=content", 0, (void*)&ft_strdup);
	environment = (char**)ft_tabpush((void**)environment, "RAV========", 0, (void*)&ft_strdup);
	environment = (char**)ft_tabpush((void**)environment, "NONE", 0, (void*)&ft_strdup);
	printf("expected 'content' got '%s'\n", get_key_value(environment, "VAR"));
	printf("expected 'content' got '%s'\n", get_key_value(environment, "VAR=content"));
	printf("expected 'content' got '%s'\n", get_key_value(environment, "VAR=nottherightcontent"));
	printf("expected '=======' got '%s'\n", get_key_value(environment, "RAV"));
	printf("expected null got '%s'\n", get_key_value(environment, "NONE"));

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

	printf("tests for push_envar:\n");
	int r, i, d;
	char *ok = "success";
	char *ko = "failure";

	r = push_envar("new_var=hello world!");
	i = ft_tabindex((const void**)environment, "new_var=hello world!", (void*)strcmp);
	printf("                        create variable %s, expected 0 got %d\n", i == -1 ? ko : ok, r);

	r = push_envar("new_var=hello moon!");
	i = ft_tabindex((const void**)environment, "new_var=hello moon!", (void*)strcmp);
	d = ft_tabindex((const void**)&environment[i + 1], "new_var=hello moon!", (void*)strcmp);
	printf("                        update variable %s, expected 0 got %d\n",
		i == -1 && d != -1 ? ko : ok, r
	);

	r = push_envar("new_var=hello moon!");
	d = ft_tabindex((const void**)&environment[i + 1], "new_var=hello moon!", (void*)strcmp);
	printf("    push identical variable and content %s, expected 0 got %d\n",
		i == -1 && d != -1 ? ko : ok, r
	);


	r = push_envar("EMPTY_VARIABLE");
	i = ft_tabindex((const void**)environment, "EMPTY_VARIABLE", (void*)strcmp);
	printf("                  create empty variable %s, expected 0 got %d\n", i == -1 ? ko : ok, r);

	r = push_envar("EMPTY_VARIABLE=update");
	i = ft_tabindex((const void**)environment, "EMPTY_VARIABLE=update", (void*)strcmp);
	d = ft_tabindex((const void**)environment, "EMPTY_VARIABLE", (void*)strcmp);
	printf("                  update empty variable %s, expected 0 got %d\n",
		i == -1 && d != -1 ? ko : ok, r
	);

	r = push_envar("EMPTY_VARIABLE");
	i = ft_tabindex((const void**)environment, "EMPTY_VARIABLE=update", (void*)strcmp);
	d = ft_tabindex((const void**)environment, "EMPTY_VARIABLE", (void*)strcmp);
	printf("not update variable with empty variable %s, expected 0 got %d\n",
		i == -1 && d != -1 ? ko : ok, r
	);

	r = push_envar("");
	i = ft_tabindex((const void**)environment, "", (void*)strcmp);
	printf("            do not push an empty string %s, expected 0 got %d\n",
		i == -1 ? ok : ko, r
	);

	r = push_envar(NULL);
	printf("        do not crash with null argument %s, expected 0 got %d\n",
		r != 0 ? ko : ok, r
	);

	ft_tabfree((void**)environment);

	return (0);
}
