# INSTALL VALGRIND
# cd ~
# rm -rf $HOME/.brew &&
# 	git clone --depth=1 https://github.com/Homebrew/brew $HOME/.brew &&
# 	echo 'export PATH=$HOME/.brew/bin:$PATH' >>$HOME/.zshrc &&
# 	source $HOME/.zshrc &&
# 	brew update
# curl https://raw.githubusercontent.com/sowson/valgrind/master/valgrind.rb >valgrind.rb
# brew install --HEAD valgrind.rb

# CLONE YOUR PROJECT
cd ~/printf/tests
git clone https://github.com/Wassaaa/ft_printf.git ft_printf
cd ft_printf
norminette
make norme

# CLONE ALL GITHUB TESTERS
git clone https://github.com/Mazoise/42TESTERS-PRINTF.git
chmod 777 */*.sh

# RUN 42TESTERS-PRINTF
cd 42TESTERS-PRINTF
bash runtest.sh
cd ..

# # RUN PFT_2019
# git clone https://github.com/gavinfielder/pft.git pft_2019 && echo "pft_2019/" >>.gitignore && cd pft_2019 && rm unit_tests.c && rm options-config.ini && git clone https://github.com/cclaude42/PFT_2019.git temp && cp temp/unit_tests.c . && cp temp/options-config.ini . && rm -rf temp
# make re
# ./test
# cd ../..

# # RUN ft_printf_test
# git clone git@github.com:cacharle/ft_printf_test.git
# cd ft_printf_test
# make run
# cd ..
