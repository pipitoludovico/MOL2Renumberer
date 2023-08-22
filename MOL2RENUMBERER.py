import sys


class MOL2Reader:
    def __init__(self):
        self.MOL2file = sys.argv[1]
        self.atomsInitials = ('C', 'N', 'O', 'S', 'F', 'H', 'B', 'P', 'I')

    def CreateAtomCounters(self):
        atomNewCount = []
        MOL2file = open(self.MOL2file, 'r')
        idx_map = {}

        for line in MOL2file.readlines():
            atomNameNum = line[8:16].strip()

            if atomNameNum.startswith(self.atomsInitials):
                if atomNameNum not in idx_map:
                    idx_map[atomNameNum] = 1
                    atomNewCount.append(atomNameNum + str(idx_map[atomNameNum]))
                else:
                    idx_map[atomNameNum] += 1
                    atomNewCount.append(atomNameNum + str(idx_map[atomNameNum]))

        MOL2file.close()
        return atomNewCount

    def ChangeAtomsInMOL2(self):
        i = 0
        atomList = self.CreateAtomCounters()
        with open(self.MOL2file.replace(".mol2", "_renumbered.mol2"), 'w') as newMOL2:
            with open(self.MOL2file, 'r') as oldMOL2:
                for oldLine in oldMOL2:
                    old_atomNameNum = oldLine[8:13].strip()
                    if not old_atomNameNum.startswith(self.atomsInitials):
                        newMOL2.write(oldLine)
                    else:
                        newMOL2.write(oldLine[:8] + atomList[i] + oldLine[12:-1] + "\n")
                        i += 1


pizza = MOL2Reader()
pizza.CreateAtomCounters()
pizza.ChangeAtomsInMOL2()
