int 	valid_base(char *basevalue);
long 	dec_converter(char *str, char *base, unsigned int baselength);
long	ft_atoi_base(char *nbr, char *base_from);
char	*convert_to(int dec_value, char *base_to, int length, int digits);
char	*ft_convert_base(char *nbr, char *base_from, char *base_to);
int	    digit_count(int dec_value, int baselength_to);

#include <unistd.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    if (argc != 4)
        return 0;

    char *answer = ft_convert_base(argv[1], argv[2], argv[3]);

    if (answer)
    {
        while (*answer)
        {
            write(1, answer, 1);
            answer++;
        }
        write(1, "\n", 1);
        free(answer - (answer - ft_convert_base("10", "0123456789", "01")));
    }
    else
    {
        write(1, "Error\n", 6);
    }

    return 0;
}