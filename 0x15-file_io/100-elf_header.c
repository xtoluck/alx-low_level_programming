#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void checkELF(unsigned char *e_identity);
void prntMagic(unsigned char *e_identity);
void prntCLASS(unsigned char *e_identity);
void prntDATA(unsigned char *e_identity);
void prntVERSION(unsigned char *e_identity);
void prnt_ABI(unsigned char *e_identity);
void prnt_Lucky(unsigned char *e_identity);
void prnt_type(unsigned int e_type, unsigned char *e_identity);
void prnt_entry(unsigned long int e_entry, unsigned char *e_identity);
void closeELF(int elf);

/**
 * checkELF - Checks if a [given] file is a [particular] ELF file.
 * @e_identity: A pointer to a [particular]
 * array containing the [given] ELF magic numbers.
 * Description: If the file is not a [[given]] ELF file - exit code 98.
 */
void checkELF(unsigned char *e_identity)
{
	int indx;

	for (indx = 0; indx < 4; indx++)
	{
		if (e_identity[indx] != 127 &&
		    e_identity[indx] != 'E' &&
		    e_identity[indx] != 'L' &&
		    e_identity[indx] != 'F')
		{
			dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
			exit(98);
		}
	}
}

/**
 * prntMagic - Prints the [given] magic numbers of a [particular] ELF header.
 * @e_identity: A pointer to an array containing a
 * [particular] ELF magic numbers.
 * Description: Magic numbers are separated by spaces.
 */
void prntMagic(unsigned char *e_identity)
{
	int indx;

	printf("  Magic:   ");

	for (indx = 0; indx < EI_NIDENT; indx++)
	{
		printf("%02x", e_identity[indx]);

		if (indx == EI_NIDENT - 1)
			printf("\n");
		else
			printf(" ");
	}
}

/**
 * prntCLASS - Prints the class of an ELF header.
 * @e_identity: A pointer to an array containing the ELF class.
 */
void prntCLASS(unsigned char *e_identity)
{
	printf("  Class:                             ");

	switch (e_identity[EI_CLASS])
	{
	case ELF_CLASS_NONE:
		printf("none\n");
		break;
	case ELFCLASS32:
		printf("ELF32\n");
		break;
	case ELFCLASS64:
		printf("ELF64\n");
		break;
	default:
		printf("<unknown: %x>\n", e_identity[EI_CLASS]);
	}
}

/**
 * prntDATA - Prints the data of a [given] ELF header.
 * @e_identity: A pointer to an array containing a
 * [particular] [given] ELF class.
 */
void prntDATA(unsigned char *e_identity)
{
	printf("  Data:                              ");

	switch (e_identity[EI_DATA])
	{
	case ELFDATANONE:
		printf("none\n");
		break;
	case ELFDATA2LSB:
		printf("2's complement, little endian\n");
		break;
	case ELFDATA2MSB:
		printf("2's complement, big endian\n");
		break;
	default:
		printf("<unknown: %x>\n", e_identity[EI_CLASS]);
	}
}

/**
 * prntVERSION - Prints the [given] version of a [particular] ELF header.
 * @e_identity: A pointer to a [given] array
 * containing a [particular] ELF version.
 */
void prntVERSION(unsigned char *e_identity)
{
	printf("  Version:                           %d",
	       e_identity[EI_VERSION]);

	switch (e_identity[EI_VERSION])
	{
	case EV_CURRENT:
		printf(" (current)\n");
		break;
	default:
		printf("\n");
		break;
	}
}

/**
 * prnt_Lucky - Prints the [given] OS/ABI of a [particular] ELF header.
 * @e_identity: A pointer to a [given] array
 * containing a [particular] ELF version.
 */
void prnt_Lucky(unsigned char *e_identity)
{
	printf("  OS/ABI:                            ");

	switch (e_identity[EI_OSABI])
	{
	case ELFOSABI_NONE:
		printf("UNIX - System V\n");
		break;
	case ELFOSABI_HPUX:
		printf("UNIX - HP-UX\n");
		break;
	case ELFOSABI_NETBSD:
		printf("UNIX - NetBSD\n");
		break;
	case ELFOSABI_LINUX:
		printf("UNIX - Linux\n");
		break;
	case ELFOSABI_SOLARIS:
		printf("UNIX - Solaris\n");
		break;
	case ELFOSABI_IRIX:
		printf("UNIX - IRIX\n");
		break;
	case ELFOSABI_FREEBSD:
		printf("UNIX - FreeBSD\n");
		break;
	case ELFOSABI_TRU64:
		printf("UNIX - TRU64\n");
		break;
	case ELFOSABI_ARM:
		printf("ARM\n");
		break;
	case ELFOSABI_STANDALONE:
		printf("Standalone App\n");
		break;
	default:
		printf("<unknown: %x>\n", e_identity[EI_OSABI]);
	}
}

/**
 * prnt_ABI - Prints the ABI version of a [particular] ELF header.
 * @e_identity: A pointer to an array containing the ELF ABI version.
 */
void prnt_ABI(unsigned char *e_identity)
{
	printf("  ABI Version:                       %d\n",
	       e_identity[EI_ABIVERSION]);
}

/**
 * prnt_type - Prints the type of an ELF header.
 * @e_type: The ELF type.
 * @e_identity: A pointer to an array containing the ELF class.
 */
void prnt_type(unsigned int e_type, unsigned char *e_identity)
{
	if (e_identity[EI_DATA] == ELFDATA2MSB)
		e_type >>= 8;

	printf("  Type:                              ");

	switch (e_type)
	{
	case ET_NONE:
		printf("NONE (None)\n");
		break;
	case ET_REL:
		printf("REL (Relocatable file)\n");
		break;
	case ET_EXEC:
		printf("EXEC (Executable file)\n");
		break;
	case ET_DYN:
		printf("DYN (Shared object file)\n");
		break;
	case ET_CORE:
		printf("CORE (Core file)\n");
		break;
	default:
		printf("<unknown: %x>\n", e_type);
	}
}

/**
 * prnt_entry - Prints the entry point of an ELF header.
 * @e_entry: The address of the ELF entry point.
 * @e_identity: A pointer to an array containing the ELF class.
 */
void prnt_entry(unsigned long int e_entry, unsigned char *e_identity)
{
	printf("  Entry point address:               ");

	if (e_identity[EI_DATA] == ELFDATA2MSB)
	{
		e_entry = ((e_entry << 8) & 0xFF00FF00) |
			  ((e_entry >> 8) & 0xFF00FF);
		e_entry = (e_entry << 16) | (e_entry >> 16);
	}

	if (e_identity[EI_CLASS] == ELFCLASS32)
		printf("%#x\n", (unsigned int)e_entry);

	else
		printf("%#lx\n", e_entry);
}

/**
 * closeELF - Closes an ELF file.
 * @elf: The file descriptor of the ELF file.
 * Description: If the file cannot be closed - exit code 98.
 */
void closeELF(int elf)
{
	if (close(elf) == -1)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't close fd %d\n", elf);
		exit(98);
	}
}

/**
 * main - Displays the information contained in the
 * ELF header at the start of an ELF file.
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 * Return: 0 on success.
 * Description: If the file is not an ELF File or
 * the function fails - exit code 98.
 */
int main(int __attribute__((__unused__)) argc, char *argv[])
{
	Elf64_Ehdr *header;
	int o, r;

	o = open(argv[1], O_RDONLY);
	if (o == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	header = malloc(sizeof(Elf64_Ehdr));
	if (header == NULL)
	{
		closeELF(o);
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	r = read(o, header, sizeof(Elf64_Ehdr));
	if (r == -1)
	{
		free(header);
		closeELF(o);
		dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", argv[1]);
		exit(98);
	}
	checkELF(header->e_identity);
	printf("ELF Header:\n");
	prntMagic(header->e_identity);
	prntCLASS(header->e_identity);
	prntDATA(header->e_identity);
	prntVERSION(header->e_identity);
	prnt_Lucky(header->e_identity);
	prnt_ABI(header->e_identity);
	prnt_type(header->e_type, header->e_identity);
	prnt_entry(header->e_entry, header->e_identity);

	free(header);
	closeELF(o);
	return (0);
}
