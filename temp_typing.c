/* Mode: Copy */
/* Function: ft_strlen */
/* Description: Returns the number of characters in the string. */
/*
   size_t ft_strlen(const char *s) {
   size_t i = 0;
   while (s[i])
   i++;
   return i;
   }
   */

// Type your implementation below:
size_t ft_strlen(const char *s) {
	size_t i = 0;
	while (s[i])
		i++;
	return i;
}
