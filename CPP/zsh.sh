function addvar
{
	local tmp="${!1}";
	tmp="${tmp//:${2}:/:}";tmp="${tmp/#${2}:/}";
	tmp="${tmp/%:${2}/}";
	echo "${2}:${tmp}";
	return;
}

TEST="/home/bin"
addvar TEST /home/ubuntu/bin

