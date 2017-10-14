#!/usr/bin/python3

import random
import math
import sys

p = 19361273351884266174179124319592617269823401300587145433371579707304323257197251225572600801370275433074684815682869385996774040032729045283074200955584697700920634678592124503629358160522441670240051067592178446440175365332023271966008760069304141521278636238815128211358422433947173241457471219513548872181437075357907618278596187147152222647874482736560267806557241239281046453532905189029107765012897084650226511831249328404686669543435470344445026858692902262616761381755495178002199002049394078728224067485791314288750599288391079845105008245855135500592368492937971623324947502042711918616017136428729009176307
g = 7459629586835995749008336515991347384570004575108335839194869046813210429266412677599497728111030288901205855079974277549165569589692181087074242211201701083480504265532866547463146311372751642956118235659927715091700943340362297123617427175357767250813943532230986395145466663495756679765391196133949789126933398911841691770692634624475509902970300052585675365716273690279111202368819321606612436768398825696347033536787546009373406300553386316277100931558540362408170576062850146257365722288850089385029902222535148043648250462830939259282013217984521099240476625973814554182880118356398351276754110170193844313822
# g is a primitive root of \mathbb{Z}_p^*

answer = ''

def generate_challenge(num):
	global answer
	x = random.randint(1, p-1)
	y = random.randint(1, p-1)
	r = random.randint(1, p-1)

	gx = pow(g, x, p)
	gy = pow(g, y, p)
	gxy = pow(gx, y, p)
	gr = pow(g, r, p)
	print('#Challenge #'+str(num))
	print('gx = '+str(gx))
	print('gy = '+str(gy))
	
	if(random.randint(1,2) == 1):
		print('g1 = '+str(gxy))
		print('g2 = '+str(gr))
		print('distinguisher(gx,gy,g1,g2)')
		answer = answer + str('1')
	else:
		print('g1 = '+str(gr))
		print('g2 = '+str(gxy))
		print('distinguisher(gx,gy,g1,g2)')
		answer = answer + str('2')

for i in range(56):
	generate_challenge(i + 1)

sys.stderr.write(answer+'\n')
