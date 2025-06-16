// bonus_functions.c
#include "core.h"
#include <stdio.h>	// for fprintf, stderr
#include <stdlib.h> // for exit

LibFunc bonus_functions[] = {
	{"ft_lstnew",
	 "Creates a new list element.",
	 "Returns a new list element or NULL if allocation fails.",
	 NULL,
	 0,
	 "t_list\t*ft_lstnew(void *content)\n"
	 "{\n"
	 "\tt_list *new;\n"
	 "\n"
	 "\tnew = (t_list *)malloc(sizeof(t_list));\n"
	 "\tif (!new)\n"
	 "\t\treturn (NULL);\n"
	 "\tnew->content = content;\n"
	 "\tnew->next = NULL;\n"
	 "\treturn (new);\n"
	 "}"},
	{"ft_lstadd_front",
	 "Adds an element at the beginning of the list.",
	 "Returns nothing.",
	 NULL,
	 0,
	 "void\tft_lstadd_front(t_list **lst, t_list *new)\n"
	 "{\n"
	 "\tif (lst && new)\n"
	 "\t{\n"
	 "\t\tnew->next = *lst;\n"
	 "\t\t*lst = new;\n"
	 "\t}\n"
	 "}"},
	{"ft_lstsize",
	 "Counts the number of elements in the list.",
	 "Returns the number of elements in the list.",
	 NULL,
	 0,
	 "int\tft_lstsize(t_list *lst)\n"
	 "{\n"
	 "\tint\tsize;\n"
	 "\n"
	 "\tsize = 0;\n"
	 "\twhile (lst)\n"
	 "\t{\n"
	 "\t\tlst = lst->next;\n"
	 "\t\tsize++;\n"
	 "\t}\n"
	 "\treturn (size);\n"
	 "}"},
	{"ft_lstlast",
	 "Returns the last element of the list.",
	 "Returns the last list element or NULL if the list is empty.",
	 NULL,
	 0,
	 "t_list\t*ft_lstlast(t_list *lst)\n"
	 "{\n"
	 "\tif (!lst)\n"
	 "\t\treturn (NULL);\n"
	 "\twhile (lst->next)\n"
	 "\t\tlst = lst->next;\n"
	 "\treturn (lst);\n"
	 "}"},
	{"ft_lstadd_back",
	 "Adds an element at the end of the list.",
	 "Returns nothing.",
	 NULL,
	 0,
	 "void\tft_lstadd_back(t_list **lst, t_list *new)\n"
	 "{\n"
	 "\tt_list *last;\n"
	 "\n"
	 "\tif (!lst || !new)\n"
	 "\t\treturn ;\n"
	 "\tif (!*lst)\n"
	 "\t{\n"
	 "\t\t*lst = new;\n"
	 "\t\treturn ;\n"
	 "\t}\n"
	 "\tlast = ft_lstlast(*lst);\n"
	 "\tlast->next = new;\n"
	 "}"},
	{"ft_lstdelone",
	 "Deletes and frees an element.",
	 "Returns nothing.",
	 NULL,
	 0,
	 "void\tft_lstdelone(t_list *lst, void (*del)(void *))\n"
	 "{\n"
	 "\tif (!lst || !del)\n"
	 "\t\treturn ;\n"
	 "\tdel(lst->content);\n"
	 "\tfree(lst);\n"
	 "}"},
	{"ft_lstclear",
	 "Deletes and frees the entire list.",
	 "Returns nothing.",
	 NULL,
	 0,
	 "void\tft_lstclear(t_list **lst, void (*del)(void *))\n"
	 "{\n"
	 "\tt_list *tmp;\n"
	 "\n"
	 "\tif (!lst || !del)\n"
	 "\t\treturn ;\n"
	 "\twhile (*lst)\n"
	 "\t{\n"
	 "\t\ttmp = (*lst)->next;\n"
	 "\t\tft_lstdelone(*lst, del);\n"
	 "\t\t*lst = tmp;\n"
	 "\t}\n"
	 "}"},
	{"ft_lstiter",
	 "Iterates the list and applies a function.",
	 "Returns nothing.",
	 NULL,
	 0,
	 "void\tft_lstiter(t_list *lst, void (*f)(void *))\n"
	 "{\n"
	 "\tif (!lst || !f)\n"
	 "\t\treturn ;\n"
	 "\twhile (lst)\n"
	 "\t{\n"
	 "\t\tf(lst->content);\n"
	 "\t\tlst = lst->next;\n"
	 "\t}\n"
	 "}"},
	{"ft_lstmap",
	 "Creates a new list applying a function to each element.",
	 "Returns a new list with applied function results or NULL if allocation fails.",
	 NULL,
	 0,
	 "t_list\t*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))\n"
	 "{\n"
	 "\tt_list *new_list;\n"
	 "\tt_list *new_elem;\n"
	 "\n"
	 "\tif (!lst || !f)\n"
	 "\t\treturn (NULL);\n"
	 "\tnew_list = NULL;\n"
	 "\twhile (lst)\n"
	 "\t{\n"
	 "\t\tnew_elem = ft_lstnew(f(lst->content));\n"
	 "\t\tif (!new_elem)\n"
	 "\t\t{\n"
	 "\t\t\tft_lstclear(&new_list, del);\n"
	 "\t\t\treturn (NULL);\n"
	 "\t\t}\n"
	 "\t\tft_lstadd_back(&new_list, new_elem);\n"
	 "\t\tlst = lst->next;\n"
	 "\t}\n"
	 "\treturn (new_list);\n"
	 "}"}};

const int BONUS_FUNC_COUNT = sizeof(bonus_functions) / sizeof(LibFunc);

LibFunc get_bonus_function_by_index(int index)
{
	if (index < 0 || index >= BONUS_FUNC_COUNT)
	{
		fprintf(stderr, "Invalid bonus function index.\n");
		exit(1);
	}
	return (bonus_functions[index]);
}

int get_bonus_function_count(void)
{
	return BONUS_FUNC_COUNT;
}
