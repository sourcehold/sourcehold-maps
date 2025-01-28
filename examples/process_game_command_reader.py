

from sourcehold.debugtools.memory import SHC
from sourcehold.structure_tools.DataProperty import DataProperty
process = SHC()

from sourcehold.structure_tools.Structure import Structure


class GameCommand(Structure):
    the_data = DataProperty("B", array_size=0x4f8)

    time = DataProperty("I", start=0)
    player = DataProperty("I", start=4)
    category = DataProperty("B", start=8)
    state_ = DataProperty("B", start=9)

    def __repr__(self):
        return f"Command<{self.time}, {self.player}, {self.category}, {self.state_}>"

    @classmethod
    def size_of(cls):
        return 0x4f8



game_commands_address = 0x01959de4
currently_processing_command_address = 0x0194af98  # ???




def read_commands():
    commands = {}
    dump = process.read_bytes(game_commands_address, 200*GameCommand.size_of())
    for i in range(200):
        command = GameCommand()

        part = dump[(i*0x4f8):((i+1)*0x4f8)]
        if set(part) == {0}:
            continue
        command.set_data(dump[(i*0x4f8):((i+1)*0x4f8)])
        commands[i] = command

    return commands


