# Leetcode 1108. Defanging an IP Address
# https://leetcode.com/problems/defanging-an-ip-address/

# @param {String} address
# @return {String}
def defang_i_paddr(address)
    address = address.gsub!".", "[.]"
end
