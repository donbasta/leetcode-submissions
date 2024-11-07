import pandas as pd

def meltTable(report: pd.DataFrame) -> pd.DataFrame:
    Q = 4
    df = pd.DataFrame({"product": [], "quarter": [], "sales": []})
    for i in range(1, 5):
        q_str = f"quarter_{i}"
        tmp = report[["product", q_str]]
        tmp = tmp.rename(columns={q_str: "sales"})
        tmp["quarter"] = q_str
        # print(tmp)
        df = pd.concat([df, tmp])
    return df
