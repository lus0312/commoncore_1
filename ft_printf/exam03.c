#include <stdarg.h>
#include <unistd.h>

int ft_putchar_fd(char c, int fd)
{
    return (write(fd, &c, 1));
}
int ft_putstr_fd(char *s, int fd)
{
    int len;
    len = 0;

    if (!s)
        return (ft_putstr_fd("(null)", fd));
    while (*s)
    {
        len += ft_putchar_fd(*s, fd);
        s++;
    }
    return (len);
}
int ft_putnbr_fd(int n, int fd)
{
    int     len;
    char    nbr;
    len = 0;
    if (n == -2147483648)
        return (write(fd, "-2147483648", 11));
    else if (n < 0)
    {
        len += write(fd, "-", 1);
        n *= -1;
    }
    if (n >= 10)
        len += ft_putnbr_fd(n / 10, fd);
    nbr = n % 10 + '0';
    len += write(fd, &nbr, 1);
    return (len);
}
int ft_putnbr_hexa(unsigned int nb, char type)
{
    char    *base;
    int     len;

    len = 0;
    if (type == 'x')
        base = "0123456789abcdef";
    else if (type == 'X')
        base = "0123456789ABCDEF";
    else
        return (-1);
    if (nb >= 16)
        len += ft_putnbr_hexa(nb / 16, type);
    len += ft_putchar_fd(base[nb % 16], 1);
    return (len); 
}

int ft_conversion(char type, va_list ap)
{
    if (type == 'x')
        return (ft_putnbr_hexa(va_arg(ap, unsigned int), type));
    else if (type == 's')
        return (ft_putstr_fd(va_arg(ap, char *), 1));
    else if (type == 'd')
        return (ft_putnbr_fd(va_arg(ap, int), 1));
    else if (type == '%')
        return (ft_putchar_fd('%', 1));
    else
        return (-1);
}

int ft_printf(const char *str, ...)
{
    va_list ap;
    int len;
    int conversion_check;

    len = 0;
    va_start(ap, str);
    while (*str)
    {
        if (*str == '%')
        {
            str++;
            conversion_check = ft_conversion(*str, ap);
            if (conversion_check == -1)
            {
                va_end(ap);
                return (-1);
            }
            len += conversion_check;
        }
        else
            len += ft_putchar_fd(*str, 1);
        str++;
    }
    va_end(ap);
    return (len);
}
