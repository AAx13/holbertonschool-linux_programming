av++;
if (!*av)
{
	printf("current directory ( )\n");
}

while (*av)
{
	switch (**av)
	{
		case '.':
			printf("current directory (.)\n");
			break;

		case '-':
			process_opt(av);
			break;

		default:
			printf("just ls directory %s\n", *av);
	}
	av++;
}
