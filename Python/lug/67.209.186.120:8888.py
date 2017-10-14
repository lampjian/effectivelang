#!/usr/bin/python3
import base64
import pickle
from flask import Flask, request

from handies import file_contents, safe_unpickle
import flag

app = Flask(__name__)


class Credential:
    "If the user wants the flag, he or she must have a credential."
    def __init__(self, username: str, password: str):
        self.username = username
        self.password = password

    def __hash__(self):
        return hash(self.username) ^ hash(self.password)

    def __str__(self):
        raise NotImplemented()


class CredentialProxy:
    "A credential proxy is an authorized credential, with its own flag."
    def __init__(self, username: str, password: str, flag: str):
        self.username = username
        self.password = password
        self.flag = flag

    def flag(self):
        return self.flag

    def __str__(self):
        return "wtf, the proxy is not supported??"


@app.route('/')
def index():
    apple = request.args.get('credential')
    if apple:
        try:
            banana = base64.b64decode(apple)
            # Good safe_unpickle can prevent 99% attacks!
            orange = safe_unpickle(banana)
            # if the orange is a credential, try it
            if isinstance(orange, Credential):
                flag.try_login(orange)
                return flag.flag
            # TODO: no proxy support
            # Time is limited, so this feature is delayed
            # return the orange to confuse the user! :-)
            else:
                return str(orange)
        except pickle.UnpicklingError as e:
            return str(e)
        except:
            return 'Wrong user or password'
    else:
        return "
" + file_contents('app.py') + "
"


app.run(host="0.0.0.0", port=8888, threaded=True)


#                            _ooOoo_
#                           o8888888o
#                           88" . "88
#                           (| -_- |)
#                           O\  =  /O
#                        ____/`---'\____
#                      .'  \\|     |//  `.
#                     /  \\|||  :  |||//  \
#                    /  _||||| -:- |||||-  \
#                    |   | \\\  -  /// |   |
#                    | \_|  ''\---/''  |   |
#                    \  .-\__  `-`  ___/-. /
#                  ___`. .'  /--.--\  `. . __
#               ."" '<  `.___\_<|>_/___.'  >'"".
#              | | :  `- \`.;`\ _ /`;.`/ - ` : | |
#              \  \ `-.   \_ __\ /__ _/   .-` /  /
#         ======`-.____`-.___\_____/___.-`____.-'======
#                            `=---='
#         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
#                    佛祖保佑        永无BUG

