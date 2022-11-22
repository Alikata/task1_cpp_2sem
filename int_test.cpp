import logging
import os
import subprocess


def system_run_command(command, ignore_stderr = True, additional_env=dict()):
    logging.debug('Run command %s', command)
    cmd_env = os.environ.copy()
    cmd_env.update(additional_env)
    p = subprocess.Popen(command, shell=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE,
                         env=cmd_env)
    output, errors = p.communicate()
    if p.returncode or (not ignore_stderr and errors):
        raise IOError("CMD = [{}]\nErrors: {}".format(command, errors if errors else "[]"))
    p.wait()
    result = output.decode("utf-8").strip()
    return result


if __name__ == "__main__":
    result = system_run_command("./wrapper Kj df ")
    assert result == "Sentense size 5\n"
