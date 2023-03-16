1:
stopper le firewall:
    FEDORA:
        sudo systemctl stop firewalld //stop le firewall
        sudo firewalld-cmd --state //check l'etat du firewall
    Ubuntu:
        sudo ufw disable
        sudo ufw status

trouver ip server:
    ip -4 addr
    l'ip ressemble a 198.162.1.xx

client -> server: EVENT
server -> client: id|texture-path|x|y|scale|rotation