*This project has been created as part of the 42 curriculum by mumidill.*

# ft_printf

## Açıklama

ft_printf, standart printf fonksiyonunun kısmi olarak yeniden yazılmış halidir.

## Talimatlar

`make all`: libftprintf.a dosyasını derler.

`make clean`: obje dosyalarını kaldırır.

`make fclean`: obje dosyalarını ve libft.a dosyasını kaldırır.

`make re`: sırasıyla fclean ve all fonksiyonlarının işlevlerini yerine getirir.

Kullanmak için projenize `#include "libftprintf.h"` şeklinde kütüphaneyi eklemeniz gerekir.

### Gereksinimler

Libftprintf kütüphanesini derlemek için güncel bir arşiv aracı, C derleyicisi ve make gerekmektedir.

### Kullanım Örneği

```c
#include "libftprintf.h"

int main(void)
{
	ft_printf("Merhaba %s, sayı: %d\n", "dünya", 42);
	return (0);
}
```

## Fonksiyon Detayı

`ft_printf` 9 farklı format belirteci ile çalışır:

| Specifier | Description |
| ----------- | ------------- |
| `%c` | Tek bir karakter yazdırır. |
| `%s` | String yazdırır. |
| `%p` | Pointer adresini hexadecimal formatında yazdırır. |
| `%d` | Signed decimal integer yazdırır. |
| `%i` | Signed decimal integer yazdırır. |
| `%u` | Unsigned decimal integer yazdırır. |
| `%x` | Unsigned integer'ı lowercase hexadecimal formatında yazdırır. |
| `%X` | Unsigned integer'ı uppercase hexadecimal formatında yazdırır. |
| `%%` | `%` karakterini yazdırır. |

`man` sayfalarındaki orijinal davranışa göre yeniden yazılmıştır.

## Kaynaklar

* Yeniden yazılmış printf fonksiyonunun `man` sayfası 
* [C23 Taslakları](https://www.open-std.org/jtc1/sc22/wg14/www/docs/n3220.pdf)
* [The C Programming Language kitabı](https://www.columbia.edu/~ng2573/c89/kr2.pdf)

### Yapay Zeka Kullanımı

Yapay zeka, makefile dosyasının düzenlenmesinde kullanılmıştır. README.md dosyasındaki yazım ve imla hataları düzeltilmiştir. Fonksiyonların işleyişi hakkında bilgi alınmıştır.