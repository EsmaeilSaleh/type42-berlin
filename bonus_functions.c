// bonus_functions.c
#include "libft_master.h"

LibFunc bonus_functions[] = {
	{
		"ft_lstnew",
		"Creates a new list element.",
		"t_list\t*ft_lstnew(void *content)\n"
			"{\n"
			"\t t_list *new;\n"
			"\n"
			"\t new = (t_list *)malloc(sizeof(t_list));\n"
			"\t if (!new)\n"
			"\t\t return (NULL);\n"
			"\t new->content = content;\n"
			"\t new->next = NULL;\n"
			"\t return (new);\n"
			"}"
	},
	{
		"ft_lstadd_front",
		"Adds an element at the beginning of the list.",
		"void\tft_lstadd_front(t_list **lst, t_list *new)\n"
			"{\n"
			"\tif (lst && new)\n"
			"\t{\n"
			"\t\tnew->next = *lst;\n"
			"\t\t*lst = new;\n"
			"\t}\n"
			"}"
	},
	{
		"ft_lstsize",
		"Counts the number of elements in the list.",
		"int\tft_lstsize(t_list *lst)\n"
			"{\n"
			"\tint\tsize = 0;\n"
			"\n"
			"\twhile (lst)\n"
			"\t{\n"
			"\t\tlst = lst->next;\n"
			"\t\tsize++;\n"
			"\t}\n"
			"\treturn (size);\n"
			"}"
	}
};
