#
#  Este arquivo contém as funcões necessárias para mostrar as imagens para a
#  selecão do teclado e do mouse de cada terminal.
#
# Copyright (C) 2004-2008 Centro de Computacao Cientifica e Software Livre
# Departamento de Informatica - Universidade Federal do Parana - C3SL/UFPR
#
# This is free software.  You may redistribute copies of it under the terms of
# the GNU General Public License <http://www.gnu.org/licenses/gpl.html>.
# There is NO WARRANTY, to the extent permitted by law.

#**********************************
#
#  File Version: 1.0.0
#                19/02/2008
#  Dependencies:
#       mdm-path.inc
#       mdm-debug.inc

#
# Esta função mostra uma imagem de acordo com o parâmetro informado
#
# Parâmetros:   tipo de imagem a ser mostrada
#                   * keyboard      mostra imagem para pressionar Fn
#                   * mouse         mostra imagem para pressionar botão do mouse
#                   * wait          mostra imagem para aguardar
#                   * reconfig      mostra imagem para reconfigurar terminal
#                   * free          exclui imagens temporárias
#
#               número do terminal sendo configurado
#

function SetImage()
{
    local FILES
    local CONVERT_ARGS="-pointsize 22 -fill #000100 -font helvetica-bold"
    local TERMINAL=${2}
    local KEYB_MSG1=$"Pressione a tecla F${TERMINAL}"
    local KEYB_MSG2=$"do teclado associado"
    local KEYB_MSG3=$"a este monitor"
    local MOUSE_MSG1=$"Pressione o botão esquerdo"
    local MOUSE_MSG2=$"do mouse associado a este"
    local MOUSE_MSG3=$"monitor"
    local RECONF_MSG1=$"Terminal configurado!"
    local RECONF_MSG2=$"Para refazer a configuracão pressione ESC."
    local RECONF_MSG3=$"Para continuar pressione ENTER."
    local WAIT_MSG=$"Aguarde..."
    
    case ${1} in
        free)
            WriteDebug $"Excluindo arquivos temporários de imagem..."
            
            # localiza arquivos temporários de imagem
            for FILES in ${TMP_DIR}/f*.png \
                         ${TMP_DIR}/mouse.png \
                         ${TMP_DIR}/wait.png \
                         ${TMP_DIR}/reconfig.png
            do
                # verifica se é um arquivo comum
                if [[ -f ${FILES} ]]; then
                    # verifica se o arquivo foi removido e grava no log
                    if rm ${FILES}; then
                        WriteDebug $"Arquivo ${FILES} removido."
                    else
                        WriteDebug $"Erro excluindo arquivo ${FILES}."
                    fi
                fi
            done
            ;;
        keyboard)
            WriteDebug $"Pressione a tecla F${TERMINAL} ..."
            
            # verifica se a imagem já existe
            if [[ ! -f ${TMP_DIR}/F${TERMINAL}.png ]]; then
                # imagem não existe. Cria imagem
                ${Convert} ${CONVERT_ARGS} \
                           -draw "text 285,365 \"${KEYB_MSG1}\"" \
                           -draw "text 285,390 \"${KEYB_MSG2}\"" \
                           -draw "text 285,415 \"${KEYB_MSG3}\"" \
                           ${IMAGE_DIR}/keyboard.png \
                           ${TMP_DIR}/F${TERMINAL}.png
                 WriteDebug "Imagem para F${TERMINAL}.png criada."
            fi
            # mostra imagem na tela
            ${ShowImage} -fullscreen ${TMP_DIR}/F${TERMINAL}.png
            ;;
        mouse)
            WriteDebug $"Imagem: Pressione o botão ... terminal ${TERMINAL}..."
            
            # verifica se a imagem já existe
            if [[ ! -f ${TMP_DIR}/mouse.png ]]; then
                ${Convert} ${CONVERT_ARGS} \
                           -draw "text 300,365 \"${MOUSE_MSG1}\"" \
                           -draw "text 300,390 \"${MOUSE_MSG2}\"" \
                           -draw "text 300,415 \"${MOUSE_MSG3}\"" \
                           ${IMAGE_DIR}/mouse.png \
                           ${TMP_DIR}/mouse.png
                WriteDebug "Imagem para mouse.png criada."
            fi
            ${ShowImage} -fullscreen ${TMP_DIR}/mouse.png
            ;;
        wait)
            WriteDebug $"Imagem: Aguarde..."
            
            # verifica se a imagem já existe
            if [[ ! -f ${TMP_DIR}/wait.png ]]; then
                ${Convert} ${CONVERT_ARGS} \
                           -draw "text 285,365 \"${WAIT_MSG}\"" \
                           ${IMAGE_DIR}/wait.png \
                           ${TMP_DIR}/wait.png
                WriteDebug "Imagem para wait.png criada."
            fi
            ${ShowImage} -fullscreen ${TMP_DIR}/wait.png
            ;;
        reconfig)
            WriteDebug $"Imagem: Pressione ESC..."
            
            # verifica se a imagem já existe
            if [[ ! -f ${TMP_DIR}/reconfig.png ]]; then
                ${Convert} ${CONVERT_ARGS} \
                           -draw "text 300,365 \"${RECONF_MSG1}\"" \
                           -draw "text 300,390 \"${RECONF_MSG2}\"" \
                           -draw "text 300,415 \"${RECONF_MSG3}\"" \
                           ${IMAGE_DIR}/reconfig.png \
                           ${TMP_DIR}/reconfig.png 
                WriteDebug $"Imagem para reconfiguracão criada."
            fi
            ${ShowImage} -fullscreen ${TMP_DIR}/reconfig.png
            ;;
        *)
            WriteDebug $"SetImage() - Opcão Inválida!!!"
            ;;
    esac
} # SetImage